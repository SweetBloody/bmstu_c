#include <stdio.h>
#include <string.h>
#include "input_string.h" // Функция ввода строки
#include "words_array.h" // Функция создания массива слов строки
#include "word_change.h" // Функция, оставляющая только первые вхождения букв в слове
#include "result_string.h" // Функция, составляющая результирующую строку из измененных слов
#include "const.h" // Константы

int main()
{
    char str[MAX_LEN_STR + 2], res_string[MAX_LEN_STR + 2];
    char words[MAX_LEN_STR / 2][MAX_LEN_WORD + 1];
    int ch, words_number = 0;

    setbuf(stdout, NULL);

    printf("Enter a string:\n");
    ch = input_string(str);

    if (ch == INPUT_ERR)
        return ch;

    if (ch == STR_OVERFLOW)
        return ch;

    if (ch == EMPTY_STR)
        return ch;

    ch = words_array(str, words, &words_number);

    if (ch == WORD_OVERFLOW)
        return ch;

    result_string(words, res_string, words_number);

    return ch;
}
