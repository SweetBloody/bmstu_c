#include <check.h>
#include <stdlib.h>
#include "check_fib.h"
#include "process.h"
#include "const.h"

START_TEST(test_fib_size_null)
{
    int size = 0;
    int *array = malloc(1 * sizeof(int));
    int ch;

    ch = fib_array(array, size);

    ck_assert_int_eq(ch, INCORRECT_SIZE);

    free(array);
}
END_TEST

START_TEST(test_fib_array_null)
{
    int size = 2;
    int ch;

    ch = fib_array(NULL, size);

    ck_assert_int_eq(ch, NULL_ARRAY);
}
END_TEST

START_TEST(test_fib_one_elem)
{
    int size = 1;
    int *array = malloc(size * sizeof(int));
    int a[] = {0};
    int ch;

    ch = fib_array(array, size);

    ck_assert_int_eq(ch, OK);
    ck_assert_mem_eq(array, a, size * sizeof(int));

    free(array);
}
END_TEST

START_TEST(test_fib_two_elems)
{
    int size = 2;
    int *array = malloc(size * sizeof(int));
    int a[] = {0, 1};
    int ch;

    ch = fib_array(array, size);

    ck_assert_int_eq(ch, OK);
    ck_assert_mem_eq(array, a, size * sizeof(int));

    free(array);
}
END_TEST

START_TEST(test_fib_many_elems)
{
    int size = 10;
    int *array = malloc(size * sizeof(int));
    int a[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    int ch;

    ch = fib_array(array, size);

    ck_assert_int_eq(ch, OK);
    ck_assert_mem_eq(array, a, size * sizeof(int));

    free(array);
}
END_TEST

Suite* fib_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("fib");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_fib_one_elem);
    tcase_add_test(tc_pos, test_fib_two_elems);
    tcase_add_test(tc_pos, test_fib_many_elems);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_fib_size_null);
    tcase_add_test(tc_neg, test_fib_array_null);
    suite_add_tcase(s, tc_neg);

    return s;
}
