#include "s21_test.h"
START_TEST(test_s21_memcpy_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Good";
  s21_size_t n = 4;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "f";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hi";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_5) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hi";
  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_6) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "love";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_7) {
  char s1[] = "new_strnew_string";
  char s2[] = "new_strnew_string";
  char s3[] = "new_string";
  s21_size_t n = strlen(s3);
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_8) {
  char s1[] = "699\017020";
  char s2[] = "699\017020";
  char s3[] = "com";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_9) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  char s3[] = "c";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_10) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  char s3[] = "com";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_11) {
  char src[] = "i hate memcmp";
  s21_size_t kByte = 12;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(test_s21_memcpy_12) {
  char src[] = "aboba";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(test_s21_memcpy_13) {
  char src[] = "";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(test_s21_memcpy_14) {
  char src[] = "I hate memcmp";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(test_s21_memcpy_15) {
  char src[] = "123";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(test_s21_memcpy_16) {
  char src[] = "aboba";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(test_s21_memcpy_17) {
  char src[] = "Zboba";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(test_s21_memcpy_18) {
  char src[] = "09";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(test_s21_memcpy_19) {
  char src[] = "abobasdafoijasdofjas asdopij";
  s21_size_t kByte = 28;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(test_s21_memcpy_20) {
  char src[] = "aposkd AOSIjFasodijpaoisdjf poisdjfg";
  s21_size_t kByte = 36;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(test_s21_memcpy_21) {
  char src[] = "aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 53;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(test_s21_memcpy_22) {
  char src[] =
      "()()(((())):!,....aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 71;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(test_s21_memcpy_23) {
  char *src = "";
  s21_size_t kByte = 71;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(test_s21_memcpy_24) {
  char *src = "";
  s21_size_t kByte = 0;
  char res[kByte];
  char expected[kByte];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

Suite *s21_memcpy_suite() {
  Suite *s;
  TCase *tc_s21_memcpy;
  s = suite_create("s21_memcpy");
  tc_s21_memcpy = tcase_create("s21_memcpy");
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_1);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_2);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_3);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_4);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_5);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_6);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_7);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_8);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_9);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_10);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_11);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_12);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_13);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_14);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_15);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_16);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_17);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_18);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_19);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_20);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_21);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_22);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_23);
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_24);
  suite_add_tcase(s, tc_s21_memcpy);

  return s;
}