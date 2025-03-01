#include "s21_test.h"
START_TEST(test_s21_strtok_1) {
  char str1[] = "Aboba++Floppa_! Kotya====!Shleppa";
  char str2[] = "Aboba++Floppa_! Kotya====!Shleppa";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    if (got || expected) {
      ck_assert_str_eq(got, expected);
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_2) {
  char str1[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  char str2[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    if (got || expected) {
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_3) {
  char str1[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  char str2[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    if (got || expected) {
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_4) {
  char str1[] = "AbobaHasNoDelims";
  char str2[] = "AbobaHasNoDelims";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    if (got || expected) {
      ck_assert_str_eq(got, expected);
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_5) {
  char str1[] = "++++++++";
  char str2[] = "++++++++";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_ptr_null(got);
  ck_assert_ptr_null(expected);
}
END_TEST

START_TEST(test_s21_strtok_6) {
  char str1[] = "Aboba_Floppa_Roba";
  char str2[] = "Aboba_Floppa_Roba";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    if (got || expected) {
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_7) {
  char str1[] = "Roba++++Kepa++A++++B__V";
  char str2[] = "Roba++++Kepa++A++++B__V";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    if (got || expected) {
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_8) {
  char str1[] = "Aboba__+Floppa_  Roba";
  char str2[] = "Aboba__+Floppa_  Roba";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    if (got || expected) {
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_9) {
  char str1[] = "Aboba__Floppa_+++Roba_Kepa";
  char str2[] = "Aboba__Floppa_+++Roba_Kepa";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    if (got || expected) {
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_10) {
  char str1[] = "     Aboba__+ Flo!ppa_   Roba+";
  char str2[] = "     Aboba__+ Flo!ppa_   Roba+";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    if (got || expected) {
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_11) {
  char str1[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  char str2[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    if (got || expected) {
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_12) {
  char str1[] = "!       A!B!C!D!E!!F!!G";
  char str2[] = "!       A!B!C!D!E!!F!!G";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    if (got || expected) {
      ck_assert_str_eq(got, expected);
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_13) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "!";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_14) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_15) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_16) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_17) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hello, world!";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_18) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_19) {
  char s1[] = "ABABABABABBABABABBABABABABABBA";
  char s2[] = "ABABABABABBABABABBABABABABABBA";
  char s3[] = "B";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_20) {
  char s1[] = "\0ABABABABABBABABABBABABABABABBA";
  char s2[] = "\0ABABABABABBABABABBABABABABABBA";
  char s3[] = "A";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_21) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_22) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_23) {
  // char *s1 = S21_NULL; // при таком обьявлении sf у обоих функций
  // char *s2 = S21_NULL;
  char s1[100] = {0};  // при таком все хорошо
  char s2[100] = {0};
  char s3[] = "";

  ck_assert_pstr_eq(strtok(s1, s3), strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_24) {
  char s1[] = "tuz-tuz-tuz";
  char s2[] = "tuz-tuz-tuz";
  char s3[] = "z-tuz-tuz";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_25) {
  char s1[] = "Hello, world! And other people";
  char s2[] = "Hello, world! And other people";
  char s3[] = "\0Come here";
  char s4[] = "\0Come here";
  char s5[] = "";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

START_TEST(test_s21_strtok_26) {
  char s1[] = "Hello,       world! And other people";
  char s2[] = "Hello,       world! And other people";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " o";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

START_TEST(test_s21_strtok_27) {
  char s1[] = "Hello,      worllllllllllld! And lother people      ";
  char s2[] = "Hello,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " l";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

START_TEST(test_s21_strtok_28) {
  char s1[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s2[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = "l";
  char s6[] = " ";

  ck_assert_str_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s6), s21_strtok(S21_NULL, s6));
  }
  ck_assert_pstr_eq(strtok(s3, s6), s21_strtok(s4, s6));
  ck_assert_pstr_eq(strtok(S21_NULL, s6), s21_strtok(S21_NULL, s6));
  ck_assert_pstr_eq(strtok(S21_NULL, s6), s21_strtok(S21_NULL, s6));
}
END_TEST

START_TEST(test_s21_strtok_29) {
  char s1[] = "ROROROROMA!!!!!!!!!";
  char s2[] = "ROROROROMA!!!!!!!!!";
  char s3[] = "R";
  strtok(s1, s3);
  strtok(NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(test_s21_strtok_30) {
  char s1[] = "AGONIA";
  char s2[] = "AGONIA";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(NULL, s3);
  strtok(NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(test_s21_strtok_31) {
  char s1[] = "MYPHONENUM68697317172648";
  char s2[] = "MYPHONENUM68697317172648";
  char s3[] = "MYPHONENUM6869";
  char *s4 = strtok(s1, s3);
  char *s6 = strtok(S21_NULL, s3);

  char *s5 = s21_strtok(s2, s3);
  char *s7 = s21_strtok(S21_NULL, s3);

  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s4, s5);
  ck_assert_pstr_eq(s6, s7);
}
END_TEST

START_TEST(test_s21_strtok_32) {
  char s1[] = "AAAAAAGOONIAAAAA";
  char s2[] = "AAAAAAGOONIAAAAA";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(NULL, s2);
  strtok(NULL, s2);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(test_s21_strtok_33) {
  char s21_str[] = "Maecenas++mollis_*_!malesuada massa=======vitae";
  char str[] = "Maecenas++mollis__!malesuada massa=======vitae";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(test_s21_strtok_34) {
  char s21_str[] = "      Maecenas++mollis__! D !malesuada _massa=======vitae ";
  char str[] = "      Maecenas++mollis__! D !malesuada _massa=======vitae ";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(test_s21_strtok_35) {
  char s21_str[] = "Maecenas++mollis__!D!malesuada_massa=======vitae";
  char str[] = "Maecenas++mollis__!D!malesuada_massa=======vitae*";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(test_s21_strtok_36) {
  char s21_str[] = "MaecenasmollisMalesuadaMassaVitae";
  char str[] = "MaecenasmollisMalesuadaMassaVitae";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(test_s21_strtok_37) {
  char s21_str[] = "++!!= _";
  char str[] = "++!!= _";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_pstr_eq(s21, system);
}
END_TEST

START_TEST(test_s21_strtok_38) {
  char s21_str[] = "Maece+*+nasmollis    !malesu     ada=massa___vitae";
  char str[] = "Maece++nasmollis    !malesu     ada=massa___vitae";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(test_s21_strtok_39) {
  char s21_str[] = "!M+*+N***L M=M_F_V*H";
  char str[] = "!M+*+N***L M=M_F_V*H";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(test_s21_strtok_40) {
  char s21_str[] =
      "        !          Maece+*+nasmol***lis    !malesu     "
      "ada=massa_f__vitae*** *** *** hi";
  char str[] =
      "        !          Maece+*+nasmol***lis    !malesu     "
      "ada=massa_f__vitae*** *** *** hi";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

Suite *s21_strtok_suite() {
  Suite *s;
  TCase *tc_s21_strtok;
  s = suite_create("s21_strtok");
  tc_s21_strtok = tcase_create("s21_strtok");
  tcase_add_test(tc_s21_strtok, test_s21_strtok_1);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_2);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_3);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_4);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_5);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_6);  // sf
  tcase_add_test(tc_s21_strtok, test_s21_strtok_7);  // sf
  tcase_add_test(tc_s21_strtok, test_s21_strtok_8);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_9);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_10);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_11);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_12);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_13);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_14);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_15);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_16);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_17);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_18);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_19);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_20);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_21);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_22);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_23);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_24);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_25);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_26);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_27);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_28);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_29);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_30);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_31);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_32);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_33);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_34);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_35);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_36);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_37);
  tcase_add_test(tc_s21_strtok, test_s21_strtok_38);  // sf
  tcase_add_test(tc_s21_strtok, test_s21_strtok_39);  // sf
  tcase_add_test(tc_s21_strtok, test_s21_strtok_40);
  //   tcase_add_test(tc_s21_strtok, test_s21_strtok_41);
  //   tcase_add_test(tc_s21_strtok, test_s21_strtok_42);

  suite_add_tcase(s, tc_s21_strtok);

  return s;
}