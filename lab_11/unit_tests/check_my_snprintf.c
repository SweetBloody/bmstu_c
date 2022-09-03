#include <check.h>
#include <stdio.h>
#include <limits.h>
#include "my_func.h"

//Тесты функции my_snprintf
START_TEST(test_my_snprintf_one_string)
{
    int ch1, ch2;
    char buf1[20], buf2[20];

    ch1 = snprintf(buf1, 20, "%s", "hello");
    ch2 = my_snprintf(buf2, 20, "%s", "hello");

    ck_assert_int_eq(ch1, ch2);
    ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_my_snprintf_two_strings)
{
    int ch1, ch2;
    char buf1[20], buf2[20];

    ch1 = snprintf(buf1, 20, "%s%s", "hello", "world");
    ch2 = my_snprintf(buf2, 20, "%s%s", "hello", "world");

    ck_assert_int_eq(ch1, ch2);
    ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_my_snprintf_two_strings_with_space)
{
    int ch1, ch2;
    char buf1[20], buf2[20];

    ch1 = snprintf(buf1, 20, "%s %s", "hello", "world");
    ch2 = my_snprintf(buf2, 20, "%s %s", "hello", "world");

    ck_assert_int_eq(ch1, ch2);
    ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_my_snprintf_string_and_num)
{
    int ch1, ch2;
    char buf1[20], buf2[20];

    ch1 = snprintf(buf1, 20, "%s%o", "hello", 254);
    ch2 = my_snprintf(buf2, 20, "%s%o", "hello", 254);

    ck_assert_int_eq(ch1, ch2);
    ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_my_snprintf_string_num_string_with_space)
{
    int ch1, ch2;
    char buf1[30], buf2[30];

    ch1 = snprintf(buf1, 30, "%s %o, %s", "hello", 254, "world");
    ch2 = my_snprintf(buf2, 30, "%s %o, %s", "hello", 254, "world");

    ck_assert_int_eq(ch1, ch2);
    ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_my_snprintf_int_max)
{
    int ch1, ch2;
    char buf1[30], buf2[30];

    ch1 = snprintf(buf1, 30, "%o", INT_MAX);
    ch2 = my_snprintf(buf2, 30, "%o", INT_MAX);

    ck_assert_int_eq(ch1, ch2);
    ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_my_snprintf_int_min)
{
    int ch1, ch2;
    char buf1[30], buf2[30];

    ch1 = snprintf(buf1, 30, "%o", INT_MIN);
    ch2 = my_snprintf(buf2, 30, "%o", INT_MIN);

    ck_assert_int_eq(ch1, ch2);
    ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_my_snprintf_int_null)
{
    int ch1, ch2;
    char buf1[30], buf2[30];

    ch1 = snprintf(buf1, 30, "%o", 0);
    ch2 = my_snprintf(buf2, 30, "%o", 0);

    ck_assert_int_eq(ch1, ch2);
    ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_my_snprintf_less_n_string)
{
    int ch1, ch2;
    char buf1[30], buf2[30];

    ch1 = snprintf(buf1, 3, "%s", "hello");
    ch2 = my_snprintf(buf2, 3, "%s", "hello");

    ck_assert_int_eq(ch1, ch2);
    ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_my_snprintf_less_n_string_num)
{
    int ch1, ch2;
    char buf1[30], buf2[30];

    ch1 = snprintf(buf1, 8, "%s %o", "hello", 36);
    ch2 = my_snprintf(buf2, 8, "%s %o", "hello", 36);

    ck_assert_int_eq(ch1, ch2);
    ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_my_snprintf_n_one)
{
    int ch1, ch2;
    char buf1[30], buf2[30];

    ch1 = snprintf(buf1, 1, "%s %o", "hello", 36);
    ch2 = my_snprintf(buf2, 1, "%s %o", "hello", 36);

    ck_assert_int_eq(ch1, ch2);
    ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_my_snprintf_n_null_buf_null)
{
    int ch1, ch2;
    char *buf1 = NULL, *buf2 = NULL;

    ch1 = snprintf(buf1, 0, "%s %o", "hello", 36);
    ch2 = my_snprintf(buf2, 0, "%s %o", "hello", 36);

    ck_assert_int_eq(ch1, ch2);
    ck_assert_ptr_null(buf1);
    ck_assert_ptr_null(buf2);
}
END_TEST


Suite* my_snprintf_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("my_snprintf:");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_my_snprintf_one_string);
    tcase_add_test(tc_pos, test_my_snprintf_two_strings);
    tcase_add_test(tc_pos, test_my_snprintf_two_strings_with_space);
    tcase_add_test(tc_pos, test_my_snprintf_string_and_num);
    tcase_add_test(tc_pos, test_my_snprintf_string_num_string_with_space);
    tcase_add_test(tc_pos, test_my_snprintf_int_max);
    tcase_add_test(tc_pos, test_my_snprintf_int_min);
    tcase_add_test(tc_pos, test_my_snprintf_int_null);
    tcase_add_test(tc_pos, test_my_snprintf_less_n_string);
    tcase_add_test(tc_pos, test_my_snprintf_less_n_string_num);
    tcase_add_test(tc_pos, test_my_snprintf_n_one);
    tcase_add_test(tc_pos, test_my_snprintf_n_null_buf_null);
    suite_add_tcase(s, tc_pos);

    return s;
}