#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  n = s21_strlen(src) < n ? s21_strlen(src) + 1 : n;
  for (; i < n; i++) {
    dest[i] = src[i];
  }
  return dest;
}
