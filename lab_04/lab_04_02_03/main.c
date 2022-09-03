#include <stdio.h>
#include <string.h>
#include "input_strings.h" // Функция ввода двух строк
#include "my_strtok.h" // Функция, разделяющая строку на слова
#include "print_single_words.h" // Функция, которая выводит неповторяющиеся в массивах слова
#include "const.h" // Константы


int main()
{
    char str1[MAX_LEN_STR + 2], str2[MAX_LEN_STR + 2];
    char words1[MAX_LEN_STR / 2][MAX_LEN_WORD + 1], words2[MAX_LEN_STR / 2][MAX_LEN_WORD + 1];
    int ch, word_number1 = 0, word_number2 = 0;

    setbuf(stdout, NULL);

    ch = input_strings(str1, str2);

    if (ch == INPUT_ERR)
        return ch;

    if (ch == STR_OVERFLOW)
        return ch;

    if (ch == EMPTY_STR)
        return ch;

    ch = my_strtok(str1, words1, &word_number1);

    if (ch == WORD_OVERFLOW)
        return ch;

    ch = my_strtok(str2, words2, &word_number2);

    if (ch == WORD_OVERFLOW)
        return ch;

    ch = print_single_words(words1, word_number1, words2, word_number2);

    return ch;
}
