#include "const.h" // Все константы, модули и функции

int main()
{
    int ch, max_1, max_2;

    ch = process(stdin, &max_1, &max_2);

    if (ch == NO_DATA)
        return ch;

    if (ch == NO_TWO_MAX)
        return ch;

    printf("%d %d", max_1, max_2);

    return OK;
}
