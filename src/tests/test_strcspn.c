#include "s21_test.h"
START_TEST(test_s21_strcspn_1) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_2) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_3) {
  char s1[] = "v";
  char s2[] = "vendetta";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_4) {
  char s1[] = "";
  char s2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_5) {
  char s1[] = "Hello, world!";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_6) {
  char s1[] = "6";
  char s2[] = "67";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_7) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_8) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_9) {
  char s1[] = "699";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_10) {
  char s1[] = "69917020";
  char s2[] = "699";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_11) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_12) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_13) {
  char src[] = "";
  char res[] = "";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_14) {
  char src[] = "gora";
  char res[] = "";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_15) {
  char src[] = "";
  char res[] = "gora";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_16) {
  char src[] = "gora";
  char res[] = "gOra";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_17) {
  char src[] = "123";
  char res[] = "123";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_18) {
  char src[] = "12345";
  char res[] = "123";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_19) {
  char src[] = "123";
  char res[] = "12345";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_20) {
  char src[] = "1234567890";
  char res[] = "0987654321";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_21) {
  char src[] = "1A2A3A4A5A";
  char res[] = "123";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_22) {
  char src[] = "a1aaa23aaa41235";
  char res[] = "123";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_23) {
  char src[] = "absD";
  char res[] = "aD";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_24) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "0987654321";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_25) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_26) {
  char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_27) {
  char src[] =
      "333333333333333333333333333333333333333333333333333333333333333"
      "33333333333333333333333";
  char res[] =
      "111111111111111111111111111111111111111111111111111111111111111"
      "11111111111111111111113";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

Suite *s21_strcspn_suite() {
  Suite *s;
  TCase *tc_s21_strcspn;
  s = suite_create("s21_strcspn");
  tc_s21_strcspn = tcase_create("s21_srtcspn");
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_1);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_2);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_3);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_4);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_5);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_6);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_7);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_8);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_9);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_10);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_11);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_12);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_13);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_14);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_15);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_16);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_17);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_18);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_19);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_20);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_21);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_22);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_23);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_24);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_25);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_26);
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_27);
  suite_add_tcase(s, tc_s21_strcspn);

  return s;
}