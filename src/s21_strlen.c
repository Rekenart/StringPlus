#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  int count = 0;
  while (str && str[count] != '\0') {
    count++;
  }
  return count;
}