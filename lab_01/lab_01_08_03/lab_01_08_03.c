#include <stdio.h>

void dec_to_bin(unsigned int num, int k)
{
    if (k == 32)
        return;
    dec_to_bin(num / 4, k + 2);
    printf("%u%u", num % 2, num / 2 % 2);
}

int main()
{
    int ch;
    unsigned int num;

    printf("Enter number:\n");
    ch = scanf("%u", &num);

    if (ch != 1)
    {
        printf("Error: incorrect enter.");
        return 1;
    }

    printf("Result: ");
    dec_to_bin(num, 0);

    return 0;
}
