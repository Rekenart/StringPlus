#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t len = s21_strlen(dest);

  for (s21_size_t i = 0; i < n && src[i] != '\0'; i++) {
    dest[len + i] = src[i];
  }
  dest[s21_strlen(dest)] = '\0';

  return dest;
}