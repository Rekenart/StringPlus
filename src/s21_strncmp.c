#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t i = 0;
  for (; str1[i] == str2[i] && i < n && str1[i] != '\0'; i++)
    ;
  return n == 0 ? 0 : n == i ? 0 : str1[i] - str2[i];
}