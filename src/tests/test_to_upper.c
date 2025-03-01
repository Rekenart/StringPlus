#include "s21_test.h"

START_TEST(s21_to_upper_1) {
  char str1[] = "abc";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABC");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_2) {
  char str1[] = "aBc";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABC");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_3) {
  char str1[] = "abC";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABC");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_4) {
  char str1[] = "ABC";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABC");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_5) {
  char str1[] = "123";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "123");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_6) {
  char str1[] = "123abc";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "123ABC");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_7) {
  char str1[] = "aBaBc";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABABC");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_8) {
  char str1[] = ".,/.,/.,";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, ".,/.,/.,");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_9) {
  char str1[] = "09876abc";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "09876ABC");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_10) {
  char str1[] = "abc123";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABC123");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_11) {
  char str1[] = " ";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, " ");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_12) {
  char str1[] = "";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_13) {
  char str1[] = "a1a1a1";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "A1A1A1");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_14) {
  char str1[] = " a1a1a1";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, " A1A1A1");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_15) {
  char str1[] = "a1a1a1 ";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "A1A1A1 ");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_16) {
  char str1[] = "Aa1a1a1";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "AA1A1A1");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_17) {
  char str1[] = "a1a1a1A";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "A1A1A1A");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_18) {
  char str1[] = "a1a1\0a1";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "A1A1\0A1");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_19) {
  char str1[] = "a1a\n1a1";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "A1A\n1A1");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_20) {
  char str1[] = "abcdefghijklmnopqrstuvwxyz";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_21) {
  char str1[] = ")(*&^YTRYUIKJHWR<LR3.,tmwnrg.";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, ")(*&^YTRYUIKJHWR<LR3.,TMWNRG.");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_22) {
  char str1[] = " ";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, " ");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_23) {
  char str1[] = "ABC";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABC");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_24) {
  char str1[] = "_az{";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "_AZ{");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_25) {
  char str1[] =
      "SDFGHJKLPOIUYTREWQWERTYUIOP["
      "OIUYTRFGHJKLJHBVNMASDFGHJKLPOIUYTREWQWERTYUIO";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2,
                   "SDFGHJKLPOIUYTREWQWERTYUIOP["
                   "OIUYTRFGHJKLJHBVNMASDFGHJKLPOIUYTREWQWERTYUIO");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_26) {
  char *str1 = (char *)s21_to_upper("slish! a nu vstal!");
  char *str2 = "SLISH! A NU VSTAL!";
  ck_assert_str_eq(str1, str2);
  free(str1);
  char *str3 = (char *)s21_to_upper("AAAAA14353423AA!!!");
  char *str4 = "AAAAA14353423AA!!!";
  ck_assert_str_eq(str3, str4);
  free(str3);
  char *str7 = (char *)s21_to_upper("KomM hieR! scHneLl!");
  char *str8 = "KOMM HIER! SCHNELL!";
  ck_assert_str_eq(str7, str8);
  free(str7);
}
END_TEST

START_TEST(s21_to_upper_27) {
  char *str1 = S21_NULL;
  char *str2 = s21_to_upper(str1);
  ck_assert_ptr_null(str2);
  free(str2);
}
END_TEST

Suite *s21_to_upper_suite() {
  Suite *s = suite_create("s21_to_upper");
  TCase *tc_s21_to_upper = tcase_create("s21_to_upper");

  tcase_add_test(tc_s21_to_upper, s21_to_upper_1);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_2);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_3);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_4);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_5);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_6);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_7);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_8);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_9);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_10);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_11);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_12);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_13);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_14);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_15);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_16);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_17);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_18);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_19);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_20);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_21);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_22);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_23);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_24);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_25);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_26);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_27);

  suite_add_tcase(s, tc_s21_to_upper);

  return s;
}