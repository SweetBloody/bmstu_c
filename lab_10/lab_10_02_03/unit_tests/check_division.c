#include <check.h>
#include <stdio.h>
#include "check_division.h"
#include "node.h"
#include "process.h"

//Тесты функции division
START_TEST(test_division_num_and_one)
{
    node_t *head_1 = NULL;
    node_t *head_2 = NULL;
    node_t *head_3 = NULL;
    node_t *head_4 = NULL;
    int array[] = {0, 1, 1};

    head_1 = num_to_simple_list(15);
    head_2 = num_to_simple_list(1);
    head_4 = create_list_by_array(array, 3);

    head_3 = division(&head_1, &head_2, 16);

    ck_assert_int_eq(list_cmp(head_3, head_4), 0);

    list_free(&head_1);
    list_free(&head_2);
    list_free(&head_3);
    list_free(&head_4);
    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(head_3);
    ck_assert_ptr_null(head_4);
}
END_TEST

START_TEST(test_division_without_remain_first)
{
    node_t *head_1 = NULL;
    node_t *head_2 = NULL;
    node_t *head_3 = NULL;
    node_t *head_4 = NULL;
    int array[] = {3, 0, 1};

    head_1 = num_to_simple_list(160);
    head_2 = num_to_simple_list(4);
    head_4 = create_list_by_array(array, 3);

    head_3 = division(&head_1, &head_2, 164);

    ck_assert_int_eq(list_cmp(head_3, head_4), 0);

    list_free(&head_1);
    list_free(&head_2);
    list_free(&head_3);
    list_free(&head_4);
    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(head_3);
    ck_assert_ptr_null(head_4);
}
END_TEST

START_TEST(test_division_without_remain_second)
{
    node_t *head_1 = NULL;
    node_t *head_2 = NULL;
    node_t *head_3 = NULL;
    node_t *head_4 = NULL;
    int array[] = {0, 0, 1};

    head_1 = num_to_simple_list(405);
    head_2 = num_to_simple_list(81);
    head_4 = create_list_by_array(array, 3);

    head_3 = division(&head_1, &head_2, 486);

    ck_assert_int_eq(list_cmp(head_3, head_4), 0);

    list_free(&head_1);
    list_free(&head_2);
    list_free(&head_3);
    list_free(&head_4);
    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(head_3);
    ck_assert_ptr_null(head_4);
}
END_TEST

START_TEST(test_division_with_remain_first)
{
    node_t *head_1 = NULL;
    node_t *head_2 = NULL;
    node_t *head_3 = NULL;
    node_t *head_4 = NULL;
    int array[] = {4, 0, 2, 1, 1};

    head_1 = num_to_simple_list(154003);
    head_2 = num_to_simple_list(5);
    head_4 = create_list_by_array(array, 5);

    head_3 = division(&head_1, &head_2, 154008);

    ck_assert_int_eq(list_cmp(head_3, head_4), 0);

    list_free(&head_1);
    list_free(&head_2);
    list_free(&head_3);
    list_free(&head_4);
    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(head_3);
    ck_assert_ptr_null(head_4);
}
END_TEST

START_TEST(test_division_with_remain_second)
{
    node_t *head_1 = NULL;
    node_t *head_2 = NULL;
    node_t *head_3 = NULL;
    node_t *head_4 = NULL;
    int array[] = {1, 1};

    head_1 = num_to_simple_list(56);
    head_2 = num_to_simple_list(9);
    head_4 = create_list_by_array(array, 2);

    head_3 = division(&head_1, &head_2, 65);

    ck_assert_int_eq(list_cmp(head_3, head_4), 0);

    list_free(&head_1);
    list_free(&head_2);
    list_free(&head_3);
    list_free(&head_4);
    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(head_3);
    ck_assert_ptr_null(head_4);
}
END_TEST

Suite* division_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("division:");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_division_num_and_one);
    tcase_add_test(tc_pos, test_division_without_remain_first);
    tcase_add_test(tc_pos, test_division_without_remain_second);
    tcase_add_test(tc_pos, test_division_with_remain_first);
    tcase_add_test(tc_pos, test_division_with_remain_second);
    suite_add_tcase(s, tc_pos);

    return s;
}