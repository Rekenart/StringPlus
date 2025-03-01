#include "s21_sprintf.h"

#include "s21_string.h"

int s21_sprintf(char *str, const char *Format, ...) {
  va_list ap;
  va_start(ap, Format);
  char *p_str = str;
  while (*Format) {
    flags f = {0};
    if (*Format != '%') {
      *p_str++ = *Format++;

      continue;
    } else {
      if (*(Format + 1) == '%') {
        *p_str++ = '%';
        Format += 2;
        continue;
      } else {
        Format++;
        Format = get_flags(Format, &f);
        Format = get_width(Format, &f);
        Format = get_length(Format, &f);
        Format = get_precision(Format, &f);
        f.specifier = *Format;
        Format++;

        char buffer2[BUFF_SIZE] = {'\0'};

        get_specifier(f, buffer2, &ap);
        for (int i = 0; buffer2[i]; i++) *p_str++ = buffer2[i];
      }
    }
  }
  va_end(ap);
  return p_str - str;
}

void get_specifier(flags f, char *buffer2, va_list *ap) {
  switch (f.specifier) {
    case 'c': {
      int width = f.width > 1 ? f.width : 1;
      s21_memset(buffer2, ' ', width - 1);
      buffer2[width - 1] = (char)va_arg(*ap, int);
      if (f.minus) {
        char tmp = buffer2[0];
        buffer2[0] = buffer2[width - 1];
        buffer2[width - 1] = tmp;
      }
      break;
    }
    case 's':
      get_specif_s(buffer2, *ap, &f);
      break;
    case 'd':
      get_specif_d_or_u(buffer2, *ap, &f);
      break;
    case 'u':
      get_specif_d_or_u(buffer2, *ap, &f);
      break;
    case 'f':
      get_specif_f(buffer2, *ap, &f);
      break;
  }
}

const char *get_flags(const char *Format, flags *f) {
  while (*Format == '-' || *Format == '+' || *Format == ' ') {
    switch (*Format) {
      case '-':
        f->minus = 1;
        break;
      case '+':
        f->plus = 1;
        break;
      case ' ':
        f->space = 1;
        break;
    }
    Format++;
  }
  return Format;
}

const char *get_width(const char *format, flags *f) {
  char tmp[BUFF_SIZE] = {'\0'};
  for (int i = 0; s21_isdigit(*format); i++, format++) tmp[i] = *format;
  f->width = s21_atoi(tmp);

  return format;
}

const char *get_length(const char *Format, flags *f) {
  switch (*Format) {
    case 'h':
      f->length = 'h';
      Format++;
      break;
    case 'l':
      f->length = 'l';
      Format++;
      break;
  }
  return Format;
}

const char *get_precision(const char *format, flags *f) {
  if (*format == '.') {
    f->is_precision_set = true;
    format++;
  }
  if (s21_isdigit(*format)) {
    char tmp[BUFF_SIZE] = {'\0'};
    for (int i = 0; s21_isdigit(*format); i++, format++) tmp[i] = *format;
    f->precision = s21_atoi(tmp);
  }
  return format;
}

void get_specif_s(char *buffer2, va_list ap, flags *f) {
  if (f->length == 'l') {
    wchar_t *wstr = va_arg(ap, wchar_t *);
    format_wide_string(f, buffer2, wstr);
  } else {
    char *str = va_arg(ap, char *);
    format_string(buffer2, f, str);
  }
}

void format_string(char *buffer2, flags *f, char *str) {
  char tmp[BUFF_SIZE] = {'\0'};
  s21_size_t ln = s21_strlen(str);
  s21_strncpy(tmp, str, ln);
  if (f->is_precision_set) tmp[f->precision] = '\0';

  int len = s21_strlen(tmp);
  int shift = f->width - len;

  if (f->minus && shift > 0) {
    s21_strncpy(buffer2, tmp, len);
    s21_memset(buffer2 + len, ' ', shift);
  } else if (shift > 0) {
    s21_memset(buffer2, ' ', shift);
    s21_strncpy(buffer2 + shift, tmp, len);
  } else {
    s21_strncpy(buffer2, tmp, len);
  }
}

void format_wide_string(flags *f, char *buffer2, wchar_t *wstr) {
  char tmp[BUFF_SIZE] = {'\0'};
  char str[BUFF_SIZE] = {'\0'};

  wcstombs(str, wstr, BUFF_SIZE);
  s21_strncpy(tmp, str, s21_strlen(str));
  format_string(buffer2, f, str);
}

void get_specif_d_or_u(char *buffer2, va_list ap, flags *f) {
  unsigned long long int value = 0;
  if (f->specifier == 'u') {
    if (f->length == 'l') {
      value = va_arg(ap, unsigned long);
    } else if (f->length == 'h') {
      value = (uint16_t)va_arg(ap, int);
    } else {
      value = va_arg(ap, unsigned int);
    }
  } else if (f->specifier == 'd') {
    if (f->length == 'l') {
      value = va_arg(ap, long long int);
    } else if (f->length == 'h') {
      value = (int16_t)va_arg(ap, int);
    } else {
      value = va_arg(ap, int);
    }
  }
  get_num_to_string(value, buffer2);
  precision_d_or_u(buffer2, f);
  format_flags(buffer2, f);
}

void get_num_to_string(long long int value, char *buffer2) {
  char tmp[BUFF_SIZE] = {'\0'};
  int idx = 0;

  bool neg = value < 0 ? 1 : 0;
  value = neg ? -value : value;
  if (value == 0) {
    tmp[idx] = '0';
    buffer2[0] = '0';
  }

  for (; value > 0; idx++, value /= 10) {
    tmp[idx] = "0123456789"[value % 10];
  }
  if (neg) {
    tmp[idx] = '-';
  } else {
    idx--;
  }

  for (int i = 0; i <= idx; i++) {
    buffer2[i] = tmp[idx - i];
  }
}

void precision_d_or_u(char *buffer2, flags *f) {
  char tmp[BUFF_SIZE] = {'\0'};

  int sign = 0;
  int len = s21_strlen(buffer2);

  if (buffer2[0] == '-') {
    tmp[0] = '-';
    len--;
    sign = 1;
  }

  if (f->precision > len) {
    int idx = 0;
    for (idx = sign; idx < f->precision - len + sign; idx++) tmp[idx] = '0';

    for (int i = sign; buffer2[i]; i++, idx++) tmp[idx] = buffer2[i];

    s21_strncpy(buffer2, tmp, s21_strlen(tmp));
  }

  if (f->is_precision_set && f->precision == 0 &&
      specs_checking(f->specifier) && buffer2[0] == '0')
    buffer2[0] = '\0';
}

bool specs_checking(char c) {
  char specs[] = {'d', 'u'};
  bool res = false;
  for (s21_size_t i = 0; i < sizeof(specs); i++) {
    if (specs[i] == c) {
      res = true;
      break;
    }
  }
  return res;
}

void format_flags(char *buffer2, flags *f) {
  char tmp[BUFF_SIZE + 1] = {'\0'};
  if (f->plus && f->specifier != 'u') {
    tmp[0] = buffer2[0] == '-' ? buffer2[0] : '+';
    s21_strncpy(tmp + 1, buffer2[0] == '-' ? buffer2 + 1 : buffer2,
                s21_strlen(buffer2));
    s21_strncpy(buffer2, tmp, s21_strlen(tmp));
  } else if (f->space && buffer2[0] != '-' && f->specifier != 'u') {
    tmp[0] = ' ';
    s21_strncpy(tmp + 1, buffer2, s21_strlen(buffer2));
    s21_strncpy(buffer2, tmp, s21_strlen(tmp));
  }
  if (f->width > (int)s21_strlen(buffer2)) {
    int idx = f->width - s21_strlen(buffer2);
    if (!f->minus) {
      s21_memset(tmp, ' ', idx);
      s21_strncpy(tmp + idx, buffer2, s21_strlen(buffer2));
    } else {
      s21_strncpy(tmp, buffer2, s21_strlen(buffer2));
      s21_memset(tmp + s21_strlen(tmp), ' ', idx);
    }
    s21_strncpy(buffer2, tmp, s21_strlen(tmp));
  }
}

void get_specif_f(char *buffer2, va_list ap, flags *f) {
  long double value = 0;
  value = va_arg(ap, double);

  if (!f->is_precision_set) {
    f->precision = 6;
  }

  double_to_string(value, buffer2, f);
  format_flags(buffer2, f);
}

void double_to_string(long double val, char *buffer2, flags *f) {
  char buff[BUFF_SIZE] = {'\0'};
  int idx = BUFF_SIZE - 2;
  bool neg = val < 0 ? 1 : 0;
  val = neg ? val * -1 : val;
  long double l = 0, r = modfl(val, &l);
  if (f->precision == 0) {
    l = roundl(val);
    r = 0;
  }
  char fractions[BUFF_SIZE] = {'\0'};
  for (int i = 0; i < f->precision; i++) {
    r = r * 10;
    fractions[i] = (int)r + '0';
  }
  long long right = roundl(r), left = l;
  if (!right) {
    for (int i = 0; i < f->precision; idx--, i++) buff[idx] = '0';
  } else {
    for (int i = s21_strlen(fractions); right || i > 0; right /= 10, idx--, i--)
      buff[idx] = (int)(right % 10 + 0.05) + '0';
  }
  if ((f->is_precision_set && f->precision != 0) || (int)r ||
      (!f->is_precision_set && val == 0) || s21_strlen(fractions))
    buff[idx--] = '.';
  if (!left) {
    buff[idx] = '0';
    idx--;
  } else {
    for (; left; left /= 10, idx--) buff[idx] = (int)(left % 10) + '0';
  }
  for (int i = 0; buff[idx + 1]; idx++, i++) {
    if (neg && i == 0) {
      buffer2[i] = '-';
      i++;
    }
    buffer2[i] = buff[idx + 1];
  }
}

int s21_isdigit(char c) { return (c >= '0' && c <= '9'); }
