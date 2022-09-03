#include <stdlib.h>
#include <string.h>
#include "cdio.h"
#include "const.h"
#include "node.h"
#include "book.h"

// Проверка файла
int file_check(char *file_name)
{
    FILE *f = fopen(file_name, "r");

    if (f == NULL)
        return FILE_OPEN_ERR;

    if (ferror(f) != 0)
        return FILE_ERR;

    if (fclose(f) == EOF)
        return FILE_CLOSE_ERR;

    return OK;
}

// Чтение строки из файла
int read_string(FILE *f, char *string)
{
    char *ch;

    ch = fgets(string, MAX_LEN + 2, f);

    if (ch == NULL)
        return INCORRECT_INPUT;

    if (string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';
    else if (strlen(string) > MAX_LEN)
        return STR_OVERFLOW;
    if (string[0] == '\0' || string[0] == '\n' || string[0] == '\t')
        return EMPTY_STR;

    return OK;
}

// Чтение числа из файла
int read_number(FILE *f, int *number)
{
    int ch;
    char n;

    ch = fscanf(f, "%d", number);
    fscanf(f, "%c", &n);

    if (ch != 1)
        return INCORRECT_INPUT;

    if (*number <= 0)
        return INCORRECT_INPUT;

    return OK;
}

// Ввод данных (целых чисел) списка из файла
int input_list_from_file_int(char *file_name, node_t **head, node_t **tail)
{
    FILE *file = fopen(file_name, "r");
    int ch, *number;

    while (!feof(file))
    {
        number = malloc(sizeof(int));
        ch = fscanf(file, "%d", number);

        if (ch != 1)
        {
            fclose(file);
            return INCORRECT_INPUT;
        }

        *tail = list_add(tail, number);

        if (!*head)
            *head = *tail;
    }

    if (!*head)
    {
        fclose(file);
        return NO_DATA;
    }

    fclose(file);

    return OK;
}

// Удаление списка
void free_list(node_t **head, node_t **tail)
{
    void *data;

    while (*head != NULL)
    {
        data = list_delete(head, tail);
        free(data);
    }

    *tail = NULL;
}

// Вывод последовательности чисел
void print_list_int(node_t *head)
{
    node_t *cur = head;

    while (cur->next != NULL)
    {
        printf("%d ", *(int*)cur->data);
        cur = cur->next;
    }
    printf("%d\n", *(int*)cur->data);
}

// Вывод последовательности чисел
void print_list_book(node_t *head)
{
    node_t *cur = head;
    book_t *book;

    while (cur != NULL)
    {
        book = (book_t*) cur->data;
        printf("%s\n%d\n\n", book->title, book->year);
        cur = cur->next;
    }
}
