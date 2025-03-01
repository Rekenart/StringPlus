#include "s21_test.h"
START_TEST(test_s21_strncpy_1) {
  char s1[20] = "Hello, world!";
  char s2[20] = "Hello, world!";
  char s3[] = "Good";
  s21_size_t n = 5;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncpy_2) {
  char s1[20] = "Hello, world!";
  char s2[20] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncpy_3) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "fг-аг-аг";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncpy_4) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncpy_5) {
  char s1[70] = "";
  char s2[70] = "";
  char s3[] =
      "I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!";
  s21_size_t n = strlen(s3);
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncpy_6) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncpy_7) {
  char *s1 = "123";
  char t1[555555] = "";
  char *s2 = "123";
  char t2[555555] = "";

  // char s3[] = "\0";
  s21_size_t n = 555555;
  char *res1 = s21_strncpy(t1, s1, n);
  char *res2 = strncpy(t2, s2, n);
  ck_assert_str_eq(t1, t2);
  ck_assert_str_eq(res1, res2);
}
END_TEST

Suite *s21_strncpy_suite() {
  Suite *s;
  TCase *tc_s21_strncpy;
  s = suite_create("s21_strncpy");
  tc_s21_strncpy = tcase_create("s21_strncpy");
  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_1);
  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_2);
  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_3);
  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_4);
  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_5);
  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_6);
  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_7);
  // tcase_add_test(tc_s21_strncpy, test_s21_strncpy_8);
  // tcase_add_test(tc_s21_strncpy, test_s21_strncpy_9);
  // tcase_add_test(tc_s21_strncpy, test_s21_strncpy_10);
  suite_add_tcase(s, tc_s21_strncpy);

  return s;
}