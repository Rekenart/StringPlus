#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *next = S21_NULL;
  char *ret = S21_NULL;
  if (str) next = str;
  while (next && *next && s21_strchr(delim, *next)) next++;
  ret = next;
  while (next && *next && !s21_strchr(delim, *next)) next++;
  if (next && *next) {
    *next = '\0';
    next++;
  } else {
    next = S21_NULL;
  }
  return ret && *ret != '\0' ? ret : S21_NULL;
}
