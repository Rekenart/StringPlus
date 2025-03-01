#include "s21_test.h"
START_TEST(test_s21_strpbrk_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(test_s21_strpbrk_2) {
  char s1[] = "Hello, world!";
  char s2[] = "!";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(test_s21_strpbrk_3) {
  char s1[] = "";
  char s2[] = "He";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(test_s21_strpbrk_4) {
  char s1[] = "\0";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(test_s21_strpbrk_5) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(test_s21_strpbrk_6) {
  char s1[] = "1242434246364377659";
  char s2[] = "364377659";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(test_s21_strpbrk_7) {
  char str1[] = "";
  char str2[] = "";

  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_8) {
  char str1[] = "floppy";
  char str2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_9) {
  char str1[] = "";
  char str2[] = "floppy";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_10) {
  char str1[] = "poki doki";
  char str2[] = "o";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_11) {
  char str1[] = "poki doki";
  char str2[] = "i";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_12) {
  char str1[] = "poki doki";
  char str2[] = "p";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_13) {
  char str1[] = "ppppppppppppP";
  char str2[] = "P";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_14) {
  char str1[] = "ppppppppppppP";
  char str2[] = "\0";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_15) {
  char s1[] = "";
  char s2[] = "Hello everyone123";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(test_s21_strpbrk_16) {
  char s1[] = "hellello";
  char s2[] = "el";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(test_s21_strpbrk_17) {
  char s1[] = "";
  char s2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(test_s21_strpbrk_18) {
  char s1[] = "Some meaningless text";
  char s2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(test_s21_strpbrk_19) {
  char s1[] = "Hello World";
  char s2[] = "World";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(test_s21_strpbrk_20) {
  char s1[] = "i need this text";
  char s2[] = "sorry";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(test_s21_strpbrk_21) {
  char s1[] = "Hello World";
  char s2[] = "world";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(test_s21_strpbrk_22) {
  char s1[] = "Hi";
  char s2[] = "i";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

Suite *s21_strpbrk_suite() {
  Suite *s;
  TCase *tc_s21_strpbrk;
  s = suite_create("s21_strpbrk");
  tc_s21_strpbrk = tcase_create("s21_strpbrk");
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_1);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_2);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_3);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_4);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_5);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_6);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_7);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_8);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_9);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_10);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_11);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_12);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_13);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_14);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_15);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_16);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_17);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_18);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_19);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_20);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_21);
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_22);

  suite_add_tcase(s, tc_s21_strpbrk);

  return s;
}