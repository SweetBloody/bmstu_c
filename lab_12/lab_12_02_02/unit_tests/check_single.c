#include <check.h>
#include <stdlib.h>
#include "check_single.h"
#include "process.h"
#include "const.h"

START_TEST(test_single_size_null)
{
    int src_size = 0, dst_size = 0;
    int *src_arr = malloc(1 * sizeof(int));
    int *dst_arr = NULL;
    int ch;

    ch = single_elems_array(src_arr, src_size, dst_arr, &dst_size);

    ck_assert_int_eq(ch, INCORRECT_SIZE);

    free(src_arr);
}
END_TEST

START_TEST(test_single_src_arr_null)
{
    int src_size = 1, dst_size = 0;
    int *src_arr = NULL;
    int *dst_arr = NULL;
    int ch;

    ch = single_elems_array(src_arr, src_size, dst_arr, &dst_size);

    ck_assert_int_eq(ch, NULL_ARRAY);
}
END_TEST

START_TEST(test_single_need_size_one)
{
    int src_size = 3, dst_size = 0;
    int src_arr[] = {1, 1, 1};
    int *dst_arr = NULL;
    int ch;

    ch = single_elems_array(src_arr, src_size, dst_arr, &dst_size);

    ck_assert_int_eq(ch, NEED_MORE_MEM);
    ck_assert_int_eq(dst_size, 1);
}
END_TEST

START_TEST(test_single_need_size_two)
{
    int src_size = 4, dst_size = 0;
    int src_arr[] = {1, 1, 1, 2};
    int *dst_arr = NULL;
    int ch;

    ch = single_elems_array(src_arr, src_size, dst_arr, &dst_size);

    ck_assert_int_eq(ch, NEED_MORE_MEM);
    ck_assert_int_eq(dst_size, 2);
}
END_TEST

START_TEST(test_single_need_size_many)
{
    int src_size = 10, dst_size = 0;
    int src_arr[] = {1, 1, 1, 2, 3, 4, 3, 5, 4, 6};
    int *dst_arr = NULL;
    int ch;

    ch = single_elems_array(src_arr, src_size, dst_arr, &dst_size);

    ck_assert_int_eq(ch, NEED_MORE_MEM);
    ck_assert_int_eq(dst_size, 6);
}
END_TEST

START_TEST(test_single_make_array_null)
{
    int src_size = 3, dst_size = 1;
    int src_arr[] = {1, 1, 1};
    int *dst_arr = NULL;
    int ch;

    ch = single_elems_array(src_arr, src_size, dst_arr, &dst_size);

    ck_assert_int_eq(ch, NULL_ARRAY);
}
END_TEST

START_TEST(test_single_make_array_one)
{
    int src_size = 3, dst_size = 1;
    int src_arr[] = {1, 1, 1};
    int *dst_arr = malloc(dst_size * sizeof(int));
    int a[] = {1};
    int ch;

    ch = single_elems_array(src_arr, src_size, dst_arr, &dst_size);

    ck_assert_int_eq(ch, OK);
    ck_assert_int_eq(dst_size, 1);
    ck_assert_mem_eq(dst_arr, a, dst_size * sizeof(int));

    free(dst_arr);
}
END_TEST

START_TEST(test_single_make_array_two)
{
    int src_size = 4, dst_size = 2;
    int src_arr[] = {1, 1, 1, 2};
    int *dst_arr = malloc(dst_size * sizeof(int));
    int a[] = {1, 2};
    int ch;

    ch = single_elems_array(src_arr, src_size, dst_arr, &dst_size);

    ck_assert_int_eq(ch, OK);
    ck_assert_int_eq(dst_size, 2);
    ck_assert_mem_eq(dst_arr, a, dst_size * sizeof(int));

    free(dst_arr);
}
END_TEST

START_TEST(test_single_make_array_many)
{
    int src_size = 10, dst_size = 6;
    int src_arr[] = {1, 1, 1, 2, 3, 4, 3, 5, 4, 6};
    int *dst_arr = malloc(dst_size * sizeof(int));
    int a[] = {1, 2, 3, 4, 5, 6};
    int ch;

    ch = single_elems_array(src_arr, src_size, dst_arr, &dst_size);

    ck_assert_int_eq(ch, OK);
    ck_assert_int_eq(dst_size, 6);
    ck_assert_mem_eq(dst_arr, a, dst_size * sizeof(int));

    free(dst_arr);
}
END_TEST


Suite* single_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("single");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_single_need_size_one);
    tcase_add_test(tc_pos, test_single_need_size_two);
    tcase_add_test(tc_pos, test_single_need_size_many);
    tcase_add_test(tc_pos, test_single_make_array_one);
    tcase_add_test(tc_pos, test_single_make_array_two);
    tcase_add_test(tc_pos, test_single_make_array_many);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_single_size_null);
    tcase_add_test(tc_neg, test_single_src_arr_null);
    tcase_add_test(tc_neg, test_single_make_array_null);
    suite_add_tcase(s, tc_neg);

    return s;
}


