#include "s21_test.h"

int main() {
  Suite *stc[] = {s21_to_upper_suite(), s21_to_lower_suite(),
                  s21_insert_suite(), s21_trim_suite(),

                  s21_strlen_suite(), s21_memchr_suite(), s21_memcmp_suite(),
                  s21_memcpy_suite(), s21_memset_suite(), s21_strtok_suite(),
                  s21_strcspn_suite(), s21_strchr_suite(), s21_strncpy_suite(),
                  s21_strncat_suite(), s21_strncmp_suite(), s21_strrchr_suite(),
                  s21_strstr_suite(), s21_strpbrk_suite(), s21_strerror_suite(),
                  s21_sprintf_suite(),

                  // s21_all_2_suite(),
                  NULL};

  for (int i = 0; stc[i]; i++) {
    putchar('\n');
    SRunner *runner = srunner_create(stc[i]);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
  }

  return 0;
}