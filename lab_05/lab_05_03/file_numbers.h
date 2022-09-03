#ifndef FILE_NUMBERS_H

#define FILE_NUMBERS_H

int get_number_by_pos(char **argv, int index); // Получение числа по номеру позиции

void put_number_by_pos(char **argv, int number, int index); // Запись числа по номеру позиции

void file_num_sort(char **argv); // Сортировка чисел в файле по возрастанию

#endif // FILE_NUMBERS_H
