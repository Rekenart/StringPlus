#include "s21_test.h"

START_TEST(s21_to_lower_1) {
  char str1[] = "ABC";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_2) {
  char str1[] = "aBc";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_3) {
  char str1[] = "abC";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_4) {
  char str1[] = "ABC";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_5) {
  char str1[] = "123";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "123");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_6) {
  char str1[] = "123ABC";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "123abc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_7) {
  char str1[] = "aBaBc";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "ababc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_8) {
  char str1[] = ".,/.,/.,";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, ".,/.,/.,");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_9) {
  char str1[] = "09876ABC";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "09876abc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_10) {
  char str1[] = "ABC123";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abc123");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_11) {
  char str1[] = " ";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, " ");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_12) {
  char str1[] = "";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_13) {
  char str1[] = "A1A1A1";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "a1a1a1");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_14) {
  char str1[] = " A1A1A1";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, " a1a1a1");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_15) {
  char str1[] = "A1A1A1 ";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "a1a1a1 ");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_16) {
  char str1[] = "AA1A1A1";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "aa1a1a1");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_17) {
  char str1[] = "A1a1A1A";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "a1a1a1a");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_18) {
  char str1[] = "A1A1\0a1";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "a1a1\0a1");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_19) {
  char str1[] = "A1a\n1A1";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "a1a\n1a1");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_20) {
  char str1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abcdefghijklmnopqrstuvwxyz");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_21) {
  char *str1 = (char *)s21_to_lower("SLISH! A NU VSTAL!");
  char *str2 = "slish! a nu vstal!";
  ck_assert_str_eq(str1, str2);
  free(str1);

  char *str3 = (char *)s21_to_lower("aaa14353423aa!!!");
  char *str4 = "aaa14353423aa!!!";
  ck_assert_str_eq(str3, str4);
  free(str3);

  char *str7 = (char *)s21_to_lower("KomM hieR! scHneLl!");
  char *str8 = "komm hier! schnell!";
  ck_assert_str_eq(str7, str8);
  free(str7);
}
END_TEST

START_TEST(s21_to_lower_22) {
  char *str1 = S21_NULL;
  char *str2 = s21_to_lower(str1);
  ck_assert_ptr_null(str2);
  free(str2);
}
END_TEST

Suite *s21_to_lower_suite() {
  Suite *s = suite_create("s21_to_lower");
  TCase *tc_s21_to_lower = tcase_create("s21_to_lower");

  tcase_add_test(tc_s21_to_lower, s21_to_lower_1);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_2);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_3);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_4);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_5);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_6);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_7);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_8);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_9);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_10);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_11);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_12);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_13);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_14);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_15);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_16);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_17);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_18);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_19);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_20);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_21);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_22);

  suite_add_tcase(s, tc_s21_to_lower);

  return s;
}