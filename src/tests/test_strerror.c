#include "s21_test.h"

START_TEST(test_s21_strerror_1) {
  for (int i = -134; i < 133; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

START_TEST(test_s21_strerror_2) {
  int n = -1;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}

END_TEST

START_TEST(test_s21_strerror_3) {
  for (int i = 133; i < 150; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
  free(strerror(150));
}
END_TEST

Suite *s21_strerror_suite() {
  Suite *s;
  TCase *tc_s21_strerror;
  s = suite_create("s21_strerror");
  tc_s21_strerror = tcase_create("s21_srterror");
  tcase_add_test(tc_s21_strerror, test_s21_strerror_1);
  tcase_add_test(tc_s21_strerror, test_s21_strerror_2);
  tcase_add_test(tc_s21_strerror, test_s21_strerror_3);
  suite_add_tcase(s, tc_s21_strerror);

  return s;
}