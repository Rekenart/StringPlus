#include "s21_test.h"
const char a[] = "Hello world";
const char b[] = "Hello world\n\0";
const char c[] = "a\n\0";
const char d[] = " \n\0";
const char e[] = " \0";
const char f[] = "\n\0";
const char g[] = "\0";
const char h[] = "1111.1";
const char i[] = "10";
START_TEST(test_s21_strlen_1) {
  ck_assert_uint_eq(s21_strlen("abc"), strlen("abc"));
}
END_TEST

START_TEST(test_s21_strlen_2) { ck_assert_uint_eq(strlen(a), s21_strlen(a)); }
END_TEST

START_TEST(test_s21_strlen_3) { ck_assert_uint_eq(strlen(b), s21_strlen(b)); }
END_TEST

START_TEST(test_s21_strlen_4) { ck_assert_uint_eq(strlen(c), s21_strlen(c)); }
END_TEST

START_TEST(test_s21_strlen_5) { ck_assert_uint_eq(strlen(d), s21_strlen(d)); }
END_TEST

START_TEST(test_s21_strlen_6) { ck_assert_uint_eq(strlen(e), s21_strlen(e)); }
END_TEST

START_TEST(test_s21_strlen_7) { ck_assert_uint_eq(strlen(f), s21_strlen(f)); }
END_TEST

START_TEST(test_s21_strlen_8) { ck_assert_uint_eq(strlen(g), s21_strlen(g)); }
END_TEST

START_TEST(test_s21_strlen_9) { ck_assert_uint_eq(strlen(h), s21_strlen(h)); }
END_TEST

START_TEST(test_s21_strlen_10) { ck_assert_uint_eq(strlen(i), s21_strlen(i)); }
END_TEST

START_TEST(test_s21_strlen_11) {
  char *str = NULL;
  ck_assert_uint_eq(0, s21_strlen(str));
}
END_TEST

Suite *s21_strlen_suite() {
  Suite *s;
  TCase *tc_s21_strlen;
  s = suite_create("s21_strlen");
  tc_s21_strlen = tcase_create("s21_srtlen");
  tcase_add_test(tc_s21_strlen, test_s21_strlen_1);
  tcase_add_test(tc_s21_strlen, test_s21_strlen_2);
  tcase_add_test(tc_s21_strlen, test_s21_strlen_3);
  tcase_add_test(tc_s21_strlen, test_s21_strlen_4);
  tcase_add_test(tc_s21_strlen, test_s21_strlen_5);
  tcase_add_test(tc_s21_strlen, test_s21_strlen_6);
  tcase_add_test(tc_s21_strlen, test_s21_strlen_7);
  tcase_add_test(tc_s21_strlen, test_s21_strlen_8);
  tcase_add_test(tc_s21_strlen, test_s21_strlen_9);
  tcase_add_test(tc_s21_strlen, test_s21_strlen_10);
  tcase_add_test(tc_s21_strlen, test_s21_strlen_11);
  suite_add_tcase(s, tc_s21_strlen);

  return s;
}