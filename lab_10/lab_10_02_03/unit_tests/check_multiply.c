#include <check.h>
#include <stdio.h>
#include "check_multiply.h"
#include "node.h"
#include "process.h"

//Тесты функции multiply
START_TEST(test_multiply_one_and_num)
{
    node_t *head_1 = NULL;
    node_t *head_2 = NULL;
    node_t *head_3 = NULL;
    int array[] = {0, 1, 1};

    head_1 = num_to_simple_list(1);
    head_2 = num_to_simple_list(15);
    head_3 = create_list_by_array(array, 3);

    muliply(&head_1, &head_2);

    ck_assert_int_eq(list_cmp(head_1, head_3), 0);

    list_free(&head_1);
    list_free(&head_2);
    list_free(&head_3);
    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(head_3);
}
END_TEST

START_TEST(test_multiply_num_and_one)
{
    node_t *head_1 = NULL;
    node_t *head_2 = NULL;
    node_t *head_3 = NULL;
    int array[] = {0, 1, 1};

    head_1 = num_to_simple_list(15);
    head_2 = num_to_simple_list(1);
    head_3 = create_list_by_array(array, 3);

    muliply(&head_1, &head_2);

    ck_assert_int_eq(list_cmp(head_1, head_3), 0);

    list_free(&head_1);
    list_free(&head_2);
    list_free(&head_3);
    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(head_3);
}
END_TEST

START_TEST(test_multiply_two_nums_increase)
{
    node_t *head_1 = NULL;
    node_t *head_2 = NULL;
    node_t *head_3 = NULL;
    int array[] = {4, 1};

    head_1 = num_to_simple_list(16);
    head_2 = num_to_simple_list(3);
    head_3 = create_list_by_array(array, 2);

    muliply(&head_1, &head_2);

    ck_assert_int_eq(list_cmp(head_1, head_3), 0);

    list_free(&head_1);
    list_free(&head_2);
    list_free(&head_3);
    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(head_3);
}
END_TEST

START_TEST(test_multiply_two_nums_decrease)
{
    node_t *head_1 = NULL;
    node_t *head_2 = NULL;
    node_t *head_3 = NULL;
    int array[] = {4, 1};

    head_1 = num_to_simple_list(3);
    head_2 = num_to_simple_list(16);
    head_3 = create_list_by_array(array, 2);

    muliply(&head_1, &head_2);

    ck_assert_int_eq(list_cmp(head_1, head_3), 0);

    list_free(&head_1);
    list_free(&head_2);
    list_free(&head_3);
    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(head_3);
}
END_TEST

START_TEST(test_multiply_two_eq_nums)
{
    node_t *head_1 = NULL;
    node_t *head_2 = NULL;
    node_t *head_3 = NULL;
    int array[] = {4, 0, 0, 2};

    head_1 = num_to_simple_list(28);
    head_2 = num_to_simple_list(28);
    head_3 = create_list_by_array(array, 4);

    muliply(&head_1, &head_2);

    ck_assert_int_eq(list_cmp(head_1, head_3), 0);

    list_free(&head_1);
    list_free(&head_2);
    list_free(&head_3);
    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(head_3);
}
END_TEST

Suite* multiply_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("multiply:");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_multiply_one_and_num);
    tcase_add_test(tc_pos, test_multiply_num_and_one);
    tcase_add_test(tc_pos, test_multiply_two_nums_increase);
    tcase_add_test(tc_pos, test_multiply_two_nums_decrease);
    tcase_add_test(tc_pos, test_multiply_two_eq_nums);
    suite_add_tcase(s, tc_pos);

    return s;
}