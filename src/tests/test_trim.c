#include "s21_test.h"

START_TEST(s21_trim_1) {
  char str1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char str2[] = "ABC";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "DEFGHIJKLMNOPQRSTUVWXYZ");
  free(str3);
}
END_TEST

START_TEST(s21_trim_2) {
  char str1[] = "ABCDEFGHIabcABCPQRSTUVWXYZ";
  char str2[] = "ABC";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "DEFGHIabcABCPQRSTUVWXYZ");
  free(str3);
}
END_TEST

START_TEST(s21_trim_3) {
  char str1[] = "ABCDEFGHIabcABCPQRSTUVWXYZABC";
  char str2[] = "ABC";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "DEFGHIabcABCPQRSTUVWXYZ");
  free(str3);
}
END_TEST

START_TEST(s21_trim_4) {
  char str1[] = "ABCDEFGHIabcABCPQRSTUVWXYZabc";
  char str2[] = "ABC";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "DEFGHIabcABCPQRSTUVWXYZabc");
  free(str3);
}
END_TEST

START_TEST(s21_trim_5) {
  char str1[] = "ABCDEFGHIabcABCPQRSTUVWXYZabc";
  char str2[] = "abc";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "ABCDEFGHIabcABCPQRSTUVWXYZ");
  free(str3);
}
END_TEST

START_TEST(s21_trim_6) {
  char str1[] = "abc123abc";
  char str2[] = "abc";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "123");
  free(str3);
}
END_TEST

START_TEST(s21_trim_7) {
  char str1[] = "abc123abc456abc";
  char str2[] = "abc";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "123abc456");
  free(str3);
}
END_TEST

START_TEST(s21_trim_8) {
  char str1[] = "a1bc123abc456a1bc";
  char str2[] = "abc";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "1bc123abc456a1");
  free(str3);
}
END_TEST

START_TEST(s21_trim_9) {
  char str1[] = "a1bc123abc456a1bc";
  char str2[] = "a1bc";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "23abc456");
  free(str3);
}
END_TEST

START_TEST(s21_trim_10) {
  char str1[] = "abc123abc456a1bc";
  char str2[] = "ab2c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "123abc456a1");
  free(str3);
}
END_TEST

START_TEST(s21_trim_11) {
  char str1[] = "abc123abc456a1bc";
  char str2[] = "ab12c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "3abc456");
  free(str3);
}
END_TEST

START_TEST(s21_trim_12) {
  char str1[] = "abAc123abc456aB1bc";
  char str2[] = "ab12c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "Ac123abc456aB");
  free(str3);
}
END_TEST

START_TEST(s21_trim_13) {
  char str1[] = "abAc123abc456aB1bc";
  char str2[] = "aBb12c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "Ac123abc456");
  free(str3);
}
END_TEST

START_TEST(s21_trim_14) {
  char str1[] = "11222333444aaaBaabaA53332244445677Babab7878998";
  char str2[] = "aBbA12c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "333444aaaBaabaA53332244445677Babab7878998");
  free(str3);
}
END_TEST

START_TEST(s21_trim_15) {
  char str1[] = "11222333444aaaBaabaA53332244445677Babab7878998";
  char str2[] = "4aB3bA12c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "53332244445677Babab7878998");
  free(str3);
}
END_TEST

START_TEST(s21_trim_16) {
  char str1[] = "11222333444aaaBaabaA53332244445677Babab7878998";
  char str2[] = "4aB37bA897c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "11222333444aaaBaabaA533322444456");
  free(str3);
}
END_TEST

START_TEST(s21_trim_17) {
  char str1[] = "11222333444aaaBaabaA53332244445677Babab7878998";
  char str2[] = "4223aB437bA189117c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "533322444456");
  free(str3);
}
END_TEST

START_TEST(s21_trim_18) {
  char str1[] = "11222333444aaaBaabaA53332244445677Babab7878998";
  char str2[] = "4223aB6437bA1589117c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(s21_trim_19) {
  char str1[] = "11222333444aaaBaabaA53332244445677Babab7878998";
  char str2[] = "jK";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "11222333444aaaBaabaA53332244445677Babab7878998");
  free(str3);
}
END_TEST

START_TEST(s21_trim_20) {
  char str1[] = "";
  char str2[] = "jK";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(s21_trim_21) {
  char str1[] = "sdfghjk";
  char str2[] = " ";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "sdfghjk");
  free(str3);
}
END_TEST

START_TEST(s21_trim_22) {
  char str1[] = "sdfg hjk";
  char str2[] = " ";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "sdfg hjk");
  free(str3);
}
END_TEST

START_TEST(s21_trim_23) {
  char str1[] = " ";
  char str2[] = " ";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(s21_trim_24) {
  char str1[] = "a231546yutiljkhgtyre565786oiu;jlkhb12";
  char str2[] = "12333333333333333333333333333333333ab";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "546yutiljkhgtyre565786oiu;jlkh");
  free(str3);
}
END_TEST

START_TEST(s21_trim_25) {
  char str1[] = "a231546yutiljkhgtyre565786oiu;jlkhb12";
  char str2[] = "12333333333333333333333333333333333abmmmmmm";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "546yutiljkhgtyre565786oiu;jlkh");
  free(str3);
}
END_TEST

START_TEST(s21_trim_26) {
  char *str = (char *)s21_trim("****skat-riba*****", "*");
  char *str2 = "skat-riba";
  ck_assert_str_eq(str, str2);
  free(str);
  char *str3 = (char *)s21_trim("Sloniki", "iki");
  char *str4 = "Slon";
  ck_assert_str_eq(str3, str4);
  free(str3);

  char *str5 = (char *)s21_trim("", "999");
  char *str6 = "";
  ck_assert_str_eq(str5, str6);
  free(str5);

  char *str7 = (char *)s21_trim("1", "huli*5682");
  char *str8 = "1";
  ck_assert_str_eq(str7, str8);
  free(str7);

  char *str9 = (char *)s21_trim("66236934599", "69");
  char *str10 = "2369345";
  ck_assert_str_eq(str9, str10);
  free(str9);
}
END_TEST

START_TEST(s21_trim_27) {
  char str[] = "";
  char trim_ch[] = "";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_28) {
  char str[] = "";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  free(got);
}
END_TEST

START_TEST(s21_trim_29) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "";
  char expected[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_30) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_31) {
  char str[] = "+!!++Abo+ba++00";
  char trim_ch[] = "+!0-";
  char expected[] = "Abo+ba";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_32) {
  char str[] = "Ab000cd0";
  char trim_ch[] = "003";
  char expected[] = "Ab000cd";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_33) {
  char str[] = "DoNotTouch";
  char trim_ch[] = "Not";
  char expected[] = "DoNotTouch";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_34) {
  char str[] = "&* !!sc21 * **";
  char trim_ch[] = "&!* ";
  char expected[] = "sc21";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_35) {
  char str[] = " Good morning!    ";
  char trim_ch[] = " ";
  char expected[] = "Good morning!";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_36) {
  char str[] = "        abc         ";
  char trim_ch[] = " ";
  char expected[] = "abc";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_37) {
  char *str1 = S21_NULL;
  char *trim_ch = " ";
  char *str2 = s21_trim(str1, trim_ch);
  ck_assert_ptr_null(str2);
  free(str2);
}
END_TEST

START_TEST(s21_trim_38) {
  char *str1 = "123";
  char *trim_ch = S21_NULL;
  char *str2 = s21_trim(str1, trim_ch);
  ck_assert_str_eq(str2, "123");
  free(str2);
}
END_TEST

Suite *s21_trim_suite() {
  Suite *s = suite_create("s21_trim");
  TCase *tc_s21_trim = tcase_create("s21_trim");

  tcase_add_test(tc_s21_trim, s21_trim_1);
  tcase_add_test(tc_s21_trim, s21_trim_2);
  tcase_add_test(tc_s21_trim, s21_trim_3);
  tcase_add_test(tc_s21_trim, s21_trim_4);
  tcase_add_test(tc_s21_trim, s21_trim_5);
  tcase_add_test(tc_s21_trim, s21_trim_6);
  tcase_add_test(tc_s21_trim, s21_trim_7);
  tcase_add_test(tc_s21_trim, s21_trim_8);
  tcase_add_test(tc_s21_trim, s21_trim_9);
  tcase_add_test(tc_s21_trim, s21_trim_10);
  tcase_add_test(tc_s21_trim, s21_trim_11);
  tcase_add_test(tc_s21_trim, s21_trim_12);
  tcase_add_test(tc_s21_trim, s21_trim_13);
  tcase_add_test(tc_s21_trim, s21_trim_14);
  tcase_add_test(tc_s21_trim, s21_trim_15);
  tcase_add_test(tc_s21_trim, s21_trim_16);
  tcase_add_test(tc_s21_trim, s21_trim_17);
  tcase_add_test(tc_s21_trim, s21_trim_18);
  tcase_add_test(tc_s21_trim, s21_trim_19);
  tcase_add_test(tc_s21_trim, s21_trim_20);
  tcase_add_test(tc_s21_trim, s21_trim_21);
  tcase_add_test(tc_s21_trim, s21_trim_22);
  tcase_add_test(tc_s21_trim, s21_trim_23);
  tcase_add_test(tc_s21_trim, s21_trim_24);
  tcase_add_test(tc_s21_trim, s21_trim_25);
  tcase_add_test(tc_s21_trim, s21_trim_26);
  tcase_add_test(tc_s21_trim, s21_trim_27);
  tcase_add_test(tc_s21_trim, s21_trim_28);
  tcase_add_test(tc_s21_trim, s21_trim_29);
  tcase_add_test(tc_s21_trim, s21_trim_30);
  tcase_add_test(tc_s21_trim, s21_trim_31);
  tcase_add_test(tc_s21_trim, s21_trim_32);
  tcase_add_test(tc_s21_trim, s21_trim_33);
  tcase_add_test(tc_s21_trim, s21_trim_34);
  tcase_add_test(tc_s21_trim, s21_trim_35);
  tcase_add_test(tc_s21_trim, s21_trim_36);
  tcase_add_test(tc_s21_trim, s21_trim_37);
  tcase_add_test(tc_s21_trim, s21_trim_38);

  suite_add_tcase(s, tc_s21_trim);

  return s;
}