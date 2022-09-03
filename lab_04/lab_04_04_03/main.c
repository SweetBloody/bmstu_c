#include <stdio.h>
#include "input_string.h" // Функция ввода строки
#include "is_number.h" // Функция, определяющая, корректно ли введен номер в строке
#include "const.h" // Константы

int main()
{
    char str[MAX_LEN_STR + 2];
    int ch;

    setbuf(stdout, NULL);

    ch = input_string(str);

    if (ch == INPUT_ERR)
        return ch;

    if (ch == STR_OVERFLOW)
        return ch;

    if (ch == EMPTY_STR)
    {
        printf("NO");
        return OK;
    }

    ch = is_number(str);

    return ch;
}
