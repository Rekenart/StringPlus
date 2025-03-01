#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t counter = 0;
  for (; !s21_strchr(str2, str1[counter]); counter++)
    ;
  return counter;
}