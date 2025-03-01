#include "s21_test.h"
START_TEST(test_s21_strrchr_1) {
  char s[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_2) {
  char s[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_3) {
  char s[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_4) {
  char s[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_5) {
  char s[] = "Hello, Polina!";
  int ch = 'P';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_6) {
  char s[] = "Hello, world!";
  int ch = 'w';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_7) {
  char s[] = "Hello, world!";
  int ch = '0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_8) {
  char s[] = "Hello, world!";
  int ch = 'm';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_9) {
  char s[] = "";
  int ch = 'm';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_10) {
  char s[10] = {0};
  int ch = 'm';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_11) {
  char s[] = "\0";
  int ch = '\n';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_12) {
  char test1[] = "0163456769";
  char test2[] = ";;;;;;H%%//#HH";
  char test3[] = "     /";
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, ' '),
                    (unsigned long)strrchr(test1, ' '));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, 'H'),
                    (unsigned long)strrchr(test2, 'H'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, '$'),
                    (unsigned long)strrchr(test2, '$'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, ';'),
                    (unsigned long)strrchr(test2, ';'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test3, ' '),
                    (unsigned long)strrchr(test3, ' '));
  ck_assert_str_eq(s21_strrchr(test2, '\0'), strrchr(test2, '\0'));
}
END_TEST

Suite *s21_strrchr_suite() {
  Suite *s;
  TCase *tc_s21_strrchr;
  s = suite_create("s21_strrchr");
  tc_s21_strrchr = tcase_create("s21_srtlen");
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_1);
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_2);
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_3);
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_4);
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_5);
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_6);
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_7);
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_8);
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_9);
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_10);
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_11);
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_12);
  suite_add_tcase(s, tc_s21_strrchr);

  return s;
}