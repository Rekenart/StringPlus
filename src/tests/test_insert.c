#include "s21_test.h"

START_TEST(s21_insert_1) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abcdef");
  free(str3);
}
END_TEST

START_TEST(s21_insert_2) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 2;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abdefc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_3) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 1;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "adefbc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_4) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 0;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "defabc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_5) {
  char str1[] = "abcdefghijkl123456789";
  char str2[] = "xyz";
  int n = 5;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abcdexyzfghijkl123456789");
  free(str3);
}
END_TEST

START_TEST(s21_insert_6) {
  char str1[] = "abc";
  char str2[] = "";
  int n = 0;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_7) {
  char str1[] = "abc";
  char str2[] = "";
  int n = 1;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_8) {
  char str1[] = "abc";
  char str2[] = "";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_9) {
  char str1[] = "";
  char str2[] = "abc";
  int n = 1;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_pstr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_10) {
  char str1[] = "";
  char str2[] = "abc";
  int n = 0;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_11) {
  char str1[] = "";
  char str2[] = "abc";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_pstr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_12) {
  char str1[] = "";
  char str2[] = "";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_pstr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_13) {
  char str1[] = "";
  char str2[] = "";
  int n = 0;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(s21_insert_14) {
  char *str1 = (char *)s21_insert("Sloniki", "iki", 2);
  char *str2 = "Slikioniki";
  ck_assert_str_eq(str1, str2);
  free(str1);
  char *str3 = (char *)s21_insert("salo", "ska", 3);
  char *str4 = "salskao";
  ck_assert_str_eq(str3, str4);
  free(str3);
  char *str5 = (char *)s21_insert("", "help", 5);
  char *str6 = S21_NULL;
  fail_unless(str5 == str6);
  free(str5);
  char *str7 = (char *)s21_insert("help!", "111", 5);
  char *str8 = "help!111";
  ck_assert_str_eq(str7, str8);
  free(str7);
}
END_TEST

START_TEST(s21_insert_15) {
  char *str1 = "SOS";
  char *str2 = S21_NULL;
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  fail_unless(str3 == S21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_16) {
  char *str1 = S21_NULL;
  char *str2 = "SOS";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  fail_unless(str3 == S21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_17) {
  char *str1 = "123";
  char *str2 = "SOS";
  int n = 6;
  char *str3 = s21_insert(str1, str2, n);
  fail_unless(str3 == S21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_18) {
  char *str1 = "123";
  char *str2 = "SOS";
  int n = -1;
  char *str3 = s21_insert(str1, str2, n);
  fail_unless(str3 == S21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_19) {
  char str[] = "Shlepa";
  char src[] = "I love my . He is very kind!";
  s21_size_t index = 10;
  char expected[] = "I love my Shlepa. He is very kind!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_insert_20) {
  char str[] = "Hello, ";
  char src[] = "Aboba!";
  s21_size_t index = 0;
  char expected[] = "Hello, Aboba!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_insert_21) {
  char src[] = "";
  char str[] = "";
  s21_size_t index = 100;
  char *expected = NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_insert_22) {
  char *src = NULL;
  char *str = NULL;
  s21_size_t index = 100;
  char *expected = NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_insert_23) {
  char str[] = "Monkey";
  char src[] = "Space  ";
  s21_size_t index = 6;
  char expected[] = "Space Monkey ";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_insert_24) {
  char *src = "123";
  char *str = "456";
  s21_size_t index = 100;
  char *expected = NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_eq(got, expected);
  if (got) free(got);
}
END_TEST

Suite *s21_insert_suite() {
  Suite *s = suite_create("s21_insert");
  TCase *tc_s21_insert = tcase_create("s21_insert");

  tcase_add_test(tc_s21_insert, s21_insert_1);
  tcase_add_test(tc_s21_insert, s21_insert_2);
  tcase_add_test(tc_s21_insert, s21_insert_3);
  tcase_add_test(tc_s21_insert, s21_insert_4);
  tcase_add_test(tc_s21_insert, s21_insert_5);
  tcase_add_test(tc_s21_insert, s21_insert_6);
  tcase_add_test(tc_s21_insert, s21_insert_7);
  tcase_add_test(tc_s21_insert, s21_insert_8);
  tcase_add_test(tc_s21_insert, s21_insert_9);
  tcase_add_test(tc_s21_insert, s21_insert_10);
  tcase_add_test(tc_s21_insert, s21_insert_11);
  tcase_add_test(tc_s21_insert, s21_insert_12);
  tcase_add_test(tc_s21_insert, s21_insert_13);
  tcase_add_test(tc_s21_insert, s21_insert_14);
  tcase_add_test(tc_s21_insert, s21_insert_15);
  tcase_add_test(tc_s21_insert, s21_insert_16);
  tcase_add_test(tc_s21_insert, s21_insert_17);
  tcase_add_test(tc_s21_insert, s21_insert_18);
  tcase_add_test(tc_s21_insert, s21_insert_19);
  tcase_add_test(tc_s21_insert, s21_insert_20);
  tcase_add_test(tc_s21_insert, s21_insert_21);
  tcase_add_test(tc_s21_insert, s21_insert_22);
  tcase_add_test(tc_s21_insert, s21_insert_23);
  tcase_add_test(tc_s21_insert, s21_insert_24);

  suite_add_tcase(s, tc_s21_insert);

  return s;
}