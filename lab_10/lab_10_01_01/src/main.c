#include <string.h>
#include "const.h"
#include "node.h"
#include "book.h"
#include "list.h"
#include "cdio.h"

int main(int argc, char **argv)
{
    node_t *head_1 = NULL, *tail_1 = NULL;
    node_t *head_2 = NULL, *tail_2 = NULL;
    node_t *res = NULL;
    void *data = NULL;
    int ch = OK;

    if (argc == 4 && strcmp(argv[3], "max") == 0)
    {
        ch = file_check(argv[1]);

        if (ch != OK)
            return ch;

        ch = file_check(argv[2]);

        if (ch != OK)
            return ch;

        ch = input_list_from_file_book(argv[1], &head_1, &tail_1);

        if (ch != OK)
        {
            free_list(&head_1, &tail_1);
            return ch;
        }

        ch = input_list_from_file_book(argv[2], &head_2, &tail_2);

        if (ch != OK)
        {
            free_list(&head_1, &tail_1);
            free_list(&head_2, &tail_2);
            return ch;
        }

        append(&head_1, &head_2);
        head_1 = sort(head_1, compare_book_year);
        data = pop_back(&head_1);
        tail_1 = get_tail(&head_1);
        printf("Book with max year:\n%s\n%d\n\n", ((book_t*)data)->title, ((book_t*)data)->year);
        free(data);
        free_list(&head_1, &tail_1);
    }
    else if (argc == 5 && strcmp(argv[2], "f") == 0)
    {
        ch = file_check(argv[1]);

        if (ch != OK)
            return ch;

        ch = input_list_from_file_book(argv[1], &head_1, &tail_1);

        if (ch != OK)
        {
            free_list(&head_1, &tail_1);
            return ch;
        }

        data = (void*) create_book(argv[3], argv[4]);

        if (!data)
        {
            free_list(&head_1, &tail_1);
            return INCORRECT_INPUT;
        }

        res = find(head_1, data, compare_book);

        if (!res)
        {
            printf("Not found!\n");
            ch = NO_DATA;
        }
        else
            printf("Fit book:\n%s\n%d\n\n", ((book_t*)res->data)->title, ((book_t*)res->data)->year);

        free(data);
        free_list(&head_1, &tail_1);
    }
    else
        ch = INCORRECT_ARGS;

    return ch;
}
