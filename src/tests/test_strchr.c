#include "s21_test.h"
START_TEST(test_s21_strchr_1) {
  char s[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_s21_strchr_2) {
  char s[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_s21_strchr_3) {
  char s[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_s21_strchr_4) {
  char s[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_s21_strchr_5) {
  char s[] = "Hello, Polina!";
  int ch = 'P';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_s21_strchr_6) {
  char s[] = "Hello, world!";
  int ch = 'w';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_s21_strchr_7) {
  char s[] = "Hello, world!";
  int ch = '0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_s21_strchr_8) {
  char s[] = "Hello, world!";
  int ch = 'm';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_s21_strchr_9) {
  char src[] = "abrakadabra";
  char find = 'a';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(test_s21_strchr_10) {
  char src[] = "abrakadAbra";
  char find = 'A';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(test_s21_strchr_11) {
  char src[] = "abrakadAbra";
  char find = '1';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(test_s21_strchr_12) {
  char src[] = "abrakadAbra";
  char find = 'Z';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(test_s21_strchr_13) {
  char src[] = "abrakadAbra";
  char find = '3';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(test_s21_strchr_14) {
  char src[] = "";
  char find = '3';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST
Suite *s21_strchr_suite() {
  Suite *s;
  TCase *tc_s21_strchr;
  s = suite_create("s21_strchr");
  tc_s21_strchr = tcase_create("s21_srtchr");
  tcase_add_test(tc_s21_strchr, test_s21_strchr_1);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_2);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_3);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_4);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_5);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_6);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_7);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_8);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_9);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_10);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_11);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_12);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_13);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_14);
  suite_add_tcase(s, tc_s21_strchr);

  return s;
}