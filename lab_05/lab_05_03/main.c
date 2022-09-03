/* Алгоритм сортировки - пузырьком
 * Направление упорядочивания - по возрастанию
 */

#include "const.h" // Все константы, модули и функции

int main(int argc, char **argv)
{
    int ch = OK;

    if (argc == 5 && strcmp(argv[2], "c") == 0)
    {
        ch = create_file(argv);

        if (ch == INCORRECT_ARGS)
            return ch;
    }
    else if (argc == 4)
    {
        if (strcmp(argv[2], "p") == 0)
        {
            ch = file_check(argv);
            if (ch == OK)
                read_file(argv);
        }
        else if (strcmp(argv[2], "s") == 0)
        {
            ch = file_check(argv);

            if (ch == OK)
                file_num_sort(argv);
        }
        else
            return INCORRECT_ARGS;
    }
    else
        return INCORRECT_ARGS;

    if (ch == INCORRECT_ARGS)
        return ch;

    if (ch == FILE_READ_ERR)
        return ch;

    if (ch == FILE_CLOSE_ERR)
        return ch;

    if (ch == FILE_ERR)
        return ch;

    return ch;
}


