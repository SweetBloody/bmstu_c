#include <stdio.h>
#include <string.h>
#include "const.h"
#include "node.h"
#include "cdio.h"
#include "process.h"

int main()
{
    node_t *head_1 = NULL;
    node_t *head_2 = NULL;
    node_t *head_3 = NULL;
    int ch = OK, number_1, number_2;
    char mode[MAX_LEN + 2];

    ch = input_string(mode);

    if (ch != OK)
        return ch;

    if (strcmp(mode, "out") == 0)
    {
        ch = input_number(&number_1);
        if (ch != OK)
            return ch;

        head_1 = num_to_simple_list(number_1);
        if (head_1 == NULL)
            return MEMORY_GET_ERROR;

        print_simple_list(head_1);
        list_free(&head_1);
    }
    else if (strcmp(mode, "mul") == 0)
    {
        ch = input_number(&number_1);
        if (ch != OK)
            return ch;

        ch = input_number(&number_2);
        if (ch != OK)
            return ch;

        head_1 = num_to_simple_list(number_1);
        if (head_1 == NULL)
            return MEMORY_GET_ERROR;

        head_2 = num_to_simple_list(number_2);
        if (head_2 == NULL)
        {
            list_free(&head_1);
            return MEMORY_GET_ERROR;
        }

        muliply(&head_1, &head_2);
        print_simple_list(head_1);
        list_free(&head_1);
        list_free(&head_2);
    }
    else if (strcmp(mode, "sqr") == 0)
    {
        ch = input_number(&number_1);
        if (ch != OK)
            return ch;

        head_1 = num_to_simple_list(number_1);
        if (head_1 == NULL)
            return MEMORY_GET_ERROR;

        sqr(&head_1);
        print_simple_list(head_1);
        list_free(&head_1);
    }
    else if (strcmp(mode, "div") == 0)
    {
        ch = input_number(&number_1);
        if (ch != OK)
            return ch;

        ch = input_number(&number_2);
        if (ch != OK)
            return ch;

        if (number_1 < number_2)
            ch = INCORRECT_DIVISION;
        else
        {
            head_1 = num_to_simple_list(number_1);
            if (head_1 == NULL)
                return MEMORY_GET_ERROR;

            head_2 = num_to_simple_list(number_2);
            if (head_2 == NULL)
            {
                list_free(&head_1);
                return MEMORY_GET_ERROR;
            }

            head_3 = division(&head_1, &head_2, number_1 + number_2);
            if (head_3 == NULL)
                return MEMORY_GET_ERROR;

            print_simple_list(head_3);
            list_free(&head_3);
        }

        list_free(&head_1);
        list_free(&head_2);
    }
    else
        ch = INCORRECT_MODE;

    return ch;
}
