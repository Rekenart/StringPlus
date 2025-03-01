#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#define BUFF_SIZE 512
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct {
  int minus;
  int plus;
  int space;
  char specifier;
  int is_precision_set;
  int precision;
  int width;
  char length;
} flags;

int s21_sprintf(char *buff, const char *format, ...);

void get_specifier(flags f, char *p_str, va_list *ap);
const char *get_flags(const char *Format, flags *f);
const char *get_width(const char *format, flags *f);
const char *get_length(const char *Format, flags *f);
const char *get_precision(const char *format, flags *f);

void get_specif_s(char *buff, va_list ap, flags *f);

void format_string(char *buff, flags *f, char *str);
void format_wide_string(flags *f, char *buffer2, wchar_t *wstr);

void get_specif_d_or_u(char *p_str, va_list ap, flags *f);
void get_num_to_string(long long int val, char *buffer2);
void precision_d_or_u(char *buff, flags *f);
bool specs_checking(char c);
void format_flags(char *buffer2, flags *f);

void get_specif_f(char *p_str, va_list ap, flags *f);
void double_to_string(long double val, char *ret, flags *f);

int s21_isdigit(char c);

#endif