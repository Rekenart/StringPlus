#include "s21_string.h"

char *s21_to_upper(const char *str) {
  char *result = S21_NULL;
  int success = 1;

  if (str == S21_NULL) {
    success = 0;
  }

  if (success) {
    s21_size_t length = s21_strlen(str) + 1;
    result = (char *)malloc(length * sizeof(char));
    if (result == S21_NULL) {
      success = 0;
    }
    if (success) {
      for (s21_size_t i = 0; i < length - 1; i++) {
        result[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : str[i];
      }
      result[length - 1] = '\0';
    }
  }
  if (!success) {
    if (result != S21_NULL) {
      free(result);
      result = S21_NULL;
    }
  }

  return result;
}

void *s21_to_lower(const char *str) {
  void *result = S21_NULL;

  if (str != S21_NULL) {
    s21_size_t length = s21_strlen(str);
    char *newStr = (char *)malloc((length + 1) * sizeof(char));

    if (newStr != S21_NULL) {
      for (s21_size_t i = 0; i < length; i++) {
        char c = str[i];
        if (c >= 'A' && c <= 'Z') {
          newStr[i] = c - 'A' + 'a';
        } else {
          newStr[i] = c;
        }
      }
      newStr[length] = '\0';
      result = (void *)newStr;
    }
  }

  return result;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  void *result = S21_NULL;

  if (src != S21_NULL && str != S21_NULL) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);

    if (start_index <= src_len) {
      char *newStr = (char *)malloc((src_len + str_len + 1) * sizeof(char));

      if (newStr != S21_NULL) {
        for (s21_size_t i = 0; i < src_len + str_len; i++) {
          if (i < start_index) {
            newStr[i] = src[i];
          } else if (i < start_index + str_len) {
            newStr[i] = str[i - start_index];
          } else {
            newStr[i] = src[i - str_len];
          }
        }
        newStr[src_len + str_len] = '\0';
        result = (void *)newStr;
      }
    }
  }

  return result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  void *result = S21_NULL;

  if (!trim_chars) {
    trim_chars = "\n\t ";
  }

  if (src != S21_NULL) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t start = 0;
    s21_size_t end = src_len;

    while (start < src_len && s21_strchr(trim_chars, src[start]) != S21_NULL) {
      start++;
    }

    while (end > start && s21_strchr(trim_chars, src[end - 1]) != S21_NULL) {
      end--;
    }

    char *newStr = (char *)malloc((end - start + 1) * sizeof(char));
    if (newStr != S21_NULL) {
      for (s21_size_t i = start; i < end; i++) {
        newStr[i - start] = src[i];
      }
      newStr[end - start] = '\0';

      result = (void *)newStr;
    }
  }

  return result;
}
