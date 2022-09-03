#include "const.h" // Все константы, модули и функции

// Получение числа по номеру позиции
int get_number_by_pos(char **argv, int index)
{
    int number;
    FILE *f = fopen(argv[3], "rb");

    fseek(f, index * sizeof(int), SEEK_SET);
    fread(&number, sizeof(int), 1, f);
    fseek(f, 0, SEEK_SET);

    fclose(f);

    return number;
}

// Запись числа по номеру позиции
void put_number_by_pos(char **argv, int number, int index)
{
    FILE *f = fopen(argv[3], "r+b");

    fseek(f, index * sizeof(int), SEEK_SET);
    fwrite(&number, sizeof(int), 1, f);
    fseek(f, 0, SEEK_SET);

    fclose(f);
}

// Сортировка чисел в файле по возрастанию
void file_num_sort(char **argv)
{
    int a, b;
    FILE *f = fopen(argv[3], "rb");
    fseek(f, 0, SEEK_END);
    int size = ftell(f) / sizeof (int);
    fseek(f, 0, SEEK_SET);
    fclose(f);

    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++)
            if (get_number_by_pos(argv, j) > get_number_by_pos(argv, j + 1))
            {
                a = get_number_by_pos(argv, j);
                b = get_number_by_pos(argv, j + 1);
                put_number_by_pos(argv, a, j + 1);
                put_number_by_pos(argv, b, j);
            }
}
