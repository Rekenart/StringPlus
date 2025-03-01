#include "s21_test.h"
START_TEST(test_s21_strstr_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(test_s21_strstr_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, P!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(test_s21_strstr_3) {
  char s1[] = "Hello, world!";
  char s2[] = "!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(test_s21_strstr_4) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] = "world";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(test_s21_strstr_5) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(test_s21_strstr_6) {
  char s1[] = "Hello, world!";
  char s2[] = "";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(test_s21_strstr_7) {
  char s1[] = "";
  char s2[] = "Hello, P!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(test_s21_strstr_8) {
  char s1[] = "69917020";
  char s2[] = "0";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(test_s21_strstr_9) {
  char s1[] = "69917020";
  char s2[] = "\0";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(test_s21_strstr_10) {
  char s1[] = "69917020";
  char s2[] = "32859160 8v3489-74 tvc4y8719c n4[nqymu uv 4vm9cw";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(test_s21_strstr_11) {
  char s1[] = "1   345 345 345 345 345";
  char s2[] = "345";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(test_s21_strstr_12) {
  char s1[] = "sususususpicioussusususpicious";
  char s2[] = "susp";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(test_s21_strstr_13) {
  char s1[] = "sus";
  char s2[] = "suspi";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST
Suite *s21_strstr_suite() {
  Suite *s;
  TCase *tc_s21_strstr;
  s = suite_create("s21_strstr");
  tc_s21_strstr = tcase_create("s21_srtstr");
  tcase_add_test(tc_s21_strstr, test_s21_strstr_1);
  tcase_add_test(tc_s21_strstr, test_s21_strstr_2);
  tcase_add_test(tc_s21_strstr, test_s21_strstr_3);
  tcase_add_test(tc_s21_strstr, test_s21_strstr_4);
  tcase_add_test(tc_s21_strstr, test_s21_strstr_5);
  tcase_add_test(tc_s21_strstr, test_s21_strstr_6);
  tcase_add_test(tc_s21_strstr, test_s21_strstr_7);
  tcase_add_test(tc_s21_strstr, test_s21_strstr_8);
  tcase_add_test(tc_s21_strstr, test_s21_strstr_9);
  tcase_add_test(tc_s21_strstr, test_s21_strstr_10);
  tcase_add_test(tc_s21_strstr, test_s21_strstr_11);
  tcase_add_test(tc_s21_strstr, test_s21_strstr_12);
  tcase_add_test(tc_s21_strstr, test_s21_strstr_13);
  suite_add_tcase(s, tc_s21_strstr);

  return s;
}