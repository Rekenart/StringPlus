#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  size_t srcptrLength = s21_strlen(needle);
  const char *result = S21_NULL;

  if (srcptrLength != 0) {
    for (int x = 0; result == S21_NULL && haystack[x] != '\0'; x += 1) {
      if (haystack[x] == needle[0]) {
        if (s21_strncmp(haystack + x, needle, srcptrLength) == 0)
          result = haystack + x;
      }
    }
  }

  return *needle == '\0' ? (char *)haystack : (char *)result;
}