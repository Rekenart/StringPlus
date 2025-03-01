#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  int strLength = s21_strlen(str);
  const char *result = S21_NULL;

  for (int x = strLength; result == S21_NULL && x >= 0; x -= 1) {
    if (str[x] == c) result = (str + x);
  }

  return (char *)result;
}