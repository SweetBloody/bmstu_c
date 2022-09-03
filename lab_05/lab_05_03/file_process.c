#include "const.h" // Все константы, модули и функции

// Проверка существования файла
int file_check(char **argv)
{
    FILE *f = fopen(argv[3], "rb");

    if (fseek(f, 0L, SEEK_END))
        return FILE_ERR;

    int size = ftell(f);

    if (size <= 0 || size % sizeof(int) != 0)
        return FILE_ERR;

    rewind(f);

    if (f == NULL)
        return FILE_READ_ERR;

    if (fclose(f) == EOF)
        return FILE_CLOSE_ERR;

    return OK;
}

// Создание файла
int create_file(char **argv)
{
    int number;
    FILE *f = fopen(argv[3], "wb");

    if (atoi(argv[4]) <= 0)
        return INCORRECT_ARGS;

    for (int i = 0; i < atoi(argv[4]); i++)
    {
        number = rand() % 1000;
        fwrite(&number, sizeof(number), 1, f);
    }

    fclose(f);

    return OK;
}

// Вывод чисел из файла
void read_file(char **argv)
{
    int number;
    FILE *f = fopen(argv[3], "rb");

    while (!feof(f))
    {
        fread(&number, sizeof(number), 1, f);

        if (!feof(f))
            printf("%d ", number);
    }

    fclose(f);
}
