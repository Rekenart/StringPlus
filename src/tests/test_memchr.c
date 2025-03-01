#include "s21_test.h"
START_TEST(test_s21_memchr_1) {
  s21_size_t n_byte = 0;
  char str[10] = "";
  int find_byte = '\0';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(test_s21_memchr_2) {
  s21_size_t n_byte = 7;
  char str[10] = "string";
  int find_byte = '\0';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(test_s21_memchr_3) {
  s21_size_t n_byte = 6;
  char str[10] = "Atring";
  int find_byte = 'A';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(test_s21_memchr_4) {
  s21_size_t n_byte = 7;
  char str[10] = "StringA";
  int find_byte = 'A';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(test_s21_memchr_5) {
  s21_size_t n_byte = 15;
  char str[16] = "Str55333222ingA";
  int find_byte = '3';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(test_s21_memchr_6) {
  int array[] = {1, 2, 3, 666, 5, 99, 100};
  s21_size_t n_byte = sizeof(int) * 7;
  int find_byte = 666;

  ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                   memchr(array, find_byte, n_byte));
}
END_TEST

START_TEST(test_s21_memchr_7) {
  float array[] = {1, 2, 3, 666, 5, 99, 100};
  s21_size_t n_byte = sizeof(float) * 7;
  int find_byte = 666;

  ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                   memchr(array, find_byte, n_byte));
}
END_TEST

START_TEST(test_s21_memchr_8) {
  s21_size_t n_byte = 5;
  char str[10] = "aboba";
  int find_byte = 'c';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(test_s21_memchr_9) {
  char test1[] = "HelloWord";
  char test2 = 'M';
  char test3 = 'r';
  char test4[] = "8919/\0";
  char test5[] = "?";
  char test6 = 'h';
  char test7 = ' ';
  char test8 = '/';
  char test9 = '\0';
  char test_8[] = "";
  char test_10[] = "1";
  char test_11 = '1';
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test2, 10),
                    (unsigned long)memchr(test1, test2, 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test3, 10),
                    (unsigned long)memchr(test1, test3, 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test6, 7),
                    (unsigned long)memchr(test4, test6, 7));
  ck_assert_uint_eq((unsigned long)s21_memchr(test5, test7, 1),
                    (unsigned long)memchr(test5, test7, 1));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test8, 7),
                    (unsigned long)memchr(test4, test8, 7));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test9, 7),
                    (unsigned long)memchr(test4, test9, 7));
  ck_assert_uint_eq((unsigned long)s21_memchr(test_8, test7, 1),
                    (unsigned long)memchr(test_8, test7, 1));
  ck_assert_uint_eq((unsigned long)s21_memchr(test_10, test_11, 1),
                    (unsigned long)memchr(test_10, test_11, 1));
}
END_TEST

START_TEST(test_s21_memchr_10) {
  char *s1 = "This is a s21_memchr test";

  ck_assert_ptr_eq(s21_memchr(s1, 's', 0), memchr(s1, 's', 0));
  ck_assert_ptr_eq(s21_memchr(s1, 's', 2), memchr(s1, 's', 2));
  ck_assert_ptr_eq(s21_memchr(s1, 's', 50), memchr(s1, 's', 50));
  ck_assert_ptr_eq(s21_memchr(s1, 'u', 50), memchr(s1, 'u', 50));
  ck_assert_ptr_eq(s21_memchr(s1, 'u', 32), memchr(s1, 'u', 32));
}

START_TEST(test_s21_memchr_11) {
  char str[] = "Hello, world!";
  int ch = ' ';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_12) {
  char str[] = "Hello, world!";
  int ch = 101;
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_13) {
  char str[] = "Hello, world!";
  int ch = '1';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_14) {
  char str[] = "Hello, world!";
  int ch = 65;
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_15) {
  char str[] = "Hello, world!";
  int ch = 'l';
  s21_size_t len = 10;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_16) {
  char str[] = "Hello, world!";
  int ch = 'w';
  s21_size_t len = 5;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_17) {
  char str[] = "69917020";
  int ch = '3';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_18) {
  char str[] = "69917020";
  int ch = '6';
  s21_size_t len = 0;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_19) {
  char str[] = "69917020";
  int ch = 'g';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_20) {
  char str[] = "69917020";
  int ch = '\0';
  s21_size_t len = 9;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

Suite *s21_memchr_suite() {
  Suite *s;
  TCase *tc_s21_memchr;
  s = suite_create("s21_memchr");
  tc_s21_memchr = tcase_create("s21_memchr");
  tcase_add_test(tc_s21_memchr, test_s21_memchr_1);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_2);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_3);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_4);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_5);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_6);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_7);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_8);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_9);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_10);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_11);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_12);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_13);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_14);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_15);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_16);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_17);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_18);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_19);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_20);
  suite_add_tcase(s, tc_s21_memchr);

  return s;
}