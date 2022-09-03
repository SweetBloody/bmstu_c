#include <check.h>
#include <stdio.h>
#include "check_sqr.h"
#include "node.h"
#include "process.h"

//Тесты функции sqr
START_TEST(test_sqr_simple_small_number)
{
    node_t *head_1 = NULL;
    node_t *head_2 = NULL;
    int array[] = {0, 0, 1};

    head_1 = num_to_simple_list(5);
    head_2 = create_list_by_array(array, 3);

    ck_assert_int_eq(list_cmp(head_1, head_2), 0);

    list_free(&head_1);
    list_free(&head_2);
    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(head_2);

}
END_TEST

START_TEST(test_sqr_simple_large_number)
{
    node_t *head_1 = NULL;
    node_t *head_2 = NULL;
    int array[] = {0, 0, 0, 0, 0, 0, 0, 0, 1};

    head_1 = num_to_simple_list(23);
    head_2 = create_list_by_array(array, 9);

    ck_assert_int_eq(list_cmp(head_1, head_2), 0);

    list_free(&head_1);
    list_free(&head_2);
    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(head_2);

}
END_TEST

START_TEST(test_sqr_small_number)
{
    node_t *head_1 = NULL;
    node_t *head_2 = NULL;
    int array[] = {2, 0, 1};

    head_1 = num_to_simple_list(20);
    head_2 = create_list_by_array(array, 3);

    ck_assert_int_eq(list_cmp(head_1, head_2), 0);

    list_free(&head_1);
    list_free(&head_2);
    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(head_2);

}
END_TEST

START_TEST(test_sqr_large_number)
{
    node_t *head_1 = NULL;
    node_t *head_2 = NULL;
    int array[] = {1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2};

    head_1 = num_to_simple_list(90774);
    head_2 = create_list_by_array(array, 13);

    ck_assert_int_eq(list_cmp(head_1, head_2), 0);

    list_free(&head_1);
    list_free(&head_2);
    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(head_2);

}
END_TEST

Suite* sqr_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("sqr:");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_sqr_simple_small_number);
    tcase_add_test(tc_pos, test_sqr_simple_large_number);
    tcase_add_test(tc_pos, test_sqr_small_number);
    tcase_add_test(tc_pos, test_sqr_large_number);
    suite_add_tcase(s, tc_pos);

    return s;
}