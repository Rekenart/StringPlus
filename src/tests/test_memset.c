#include "s21_test.h"
START_TEST(test_s21_memset_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  s21_size_t n = strlen(s1);
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(test_s21_memset_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  s21_size_t n = 5;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(test_s21_memset_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(test_s21_memset_4) {
  char s1[] = "";
  char s2[] = "";
  int ch = '\0';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(test_s21_memset_5) {
  char s1[] = "Hello";
  char s2[] = "Hello";
  int ch = '\0';
  s21_size_t n = 4;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(test_s21_memset_6) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = 80;
  s21_size_t n = 7;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(test_s21_memset_7) {
  char res[] = "aboba";
  char expected[] = "aboba";
  char replace = 'g';
  s21_size_t n_byte = 5;

  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(test_s21_memset_8) {
  char res[] = "aboba";
  char expected[] = "aboba";
  char replace = 'g';
  s21_size_t n_byte = 0;

  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);

  ck_assert_str_eq(res, expected);
}
END_TEST
START_TEST(test_s21_memset_9) {
  char res[] = "";
  char expected[] = "";
  char replace = '\0';
  s21_size_t n_byte = 0;

  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(test_s21_memset_10) {
  char res[] = "aboba";
  char expected[] = "aboba";
  char replace = 'A';
  s21_size_t n_byte = 3;

  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(test_s21_memset_11) {
  char res[] = "a1obA";
  char expected[] = "a1obA";
  char replace = '1';
  s21_size_t n_byte = 5;

  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(test_s21_memset_12) {
  char res[] =
      "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 "
      "hiajhIOUAHSDiouAHSdu1).bA";
  char expected[] =
      "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 "
      "hiajhIOUAHSDiouAHSdu1).bA";
  char replace = '1';
  s21_size_t n_byte = 5;

  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(test_s21_memset_13) {
  s21_size_t n_byte = 0;
  char str[10] = "";
  int find_byte = '\0';

  ck_assert_ptr_eq(s21_memset(str, find_byte, n_byte),
                   memset(str, find_byte, n_byte));
}
END_TEST

START_TEST(test_s21_memset_14) {
  s21_size_t n_byte = 7;
  char str[10] = "string";
  int find_byte = '\0';

  ck_assert_ptr_eq(s21_memset(str, find_byte, n_byte),
                   memset(str, find_byte, n_byte));
}
END_TEST

START_TEST(test_s21_memset_15) {
  s21_size_t n_byte = 6;
  char str[10] = "Atring";
  int find_byte = 'A';

  ck_assert_ptr_eq(s21_memset(str, find_byte, n_byte),
                   memset(str, find_byte, n_byte));
}
END_TEST

START_TEST(test_s21_memset_16) {
  s21_size_t n_byte = 7;
  char str[10] = "StringA";
  int find_byte = 'A';

  ck_assert_ptr_eq(s21_memset(str, find_byte, n_byte),
                   memset(str, find_byte, n_byte));
}
END_TEST

START_TEST(test_s21_memset_17) {
  s21_size_t n_byte = 15;
  char str[16] = "Str55333222ingA";
  int find_byte = '3';

  ck_assert_ptr_eq(s21_memset(str, find_byte, n_byte),
                   memset(str, find_byte, n_byte));
}
END_TEST

START_TEST(test_s21_memset_18) {
  int array[] = {1, 2, 3, 666, 5, 99, 100};
  s21_size_t n_byte = sizeof(int) * 7;
  int find_byte = 666;

  ck_assert_ptr_eq(s21_memset(array, find_byte, n_byte),
                   memset(array, find_byte, n_byte));
}
END_TEST

START_TEST(test_s21_memset_19) {
  float array[] = {1, 2, 3, 666, 5, 99, 100};
  s21_size_t n_byte = sizeof(float) * 7;
  int find_byte = 666;

  ck_assert_ptr_eq(s21_memset(array, find_byte, n_byte),
                   memset(array, find_byte, n_byte));
}
END_TEST

START_TEST(test_s21_memset_20) {
  s21_size_t n_byte = 5;
  char str[10] = "aboba";
  int find_byte = 'c';

  ck_assert_ptr_eq(s21_memset(str, find_byte, n_byte),
                   memset(str, find_byte, n_byte));
}
END_TEST

Suite *s21_memset_suite() {
  Suite *s;
  TCase *tc_s21_memset;
  s = suite_create("s21_memset");
  tc_s21_memset = tcase_create("s21_memset");
  tcase_add_test(tc_s21_memset, test_s21_memset_1);
  tcase_add_test(tc_s21_memset, test_s21_memset_2);
  tcase_add_test(tc_s21_memset, test_s21_memset_3);
  tcase_add_test(tc_s21_memset, test_s21_memset_4);
  tcase_add_test(tc_s21_memset, test_s21_memset_5);
  tcase_add_test(tc_s21_memset, test_s21_memset_6);
  tcase_add_test(tc_s21_memset, test_s21_memset_7);
  tcase_add_test(tc_s21_memset, test_s21_memset_8);
  tcase_add_test(tc_s21_memset, test_s21_memset_9);
  tcase_add_test(tc_s21_memset, test_s21_memset_10);
  tcase_add_test(tc_s21_memset, test_s21_memset_11);
  tcase_add_test(tc_s21_memset, test_s21_memset_12);
  tcase_add_test(tc_s21_memset, test_s21_memset_13);
  tcase_add_test(tc_s21_memset, test_s21_memset_14);
  tcase_add_test(tc_s21_memset, test_s21_memset_15);
  tcase_add_test(tc_s21_memset, test_s21_memset_16);
  tcase_add_test(tc_s21_memset, test_s21_memset_17);
  tcase_add_test(tc_s21_memset, test_s21_memset_18);
  tcase_add_test(tc_s21_memset, test_s21_memset_19);
  tcase_add_test(tc_s21_memset, test_s21_memset_20);
  suite_add_tcase(s, tc_s21_memset);

  return s;
}