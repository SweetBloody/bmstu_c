#include <stdio.h>
#include <math.h>

int main()
{
    int sec, min, hour;

    printf("Enter number of seconds:\n");
    scanf("%d", &sec);

    min = sec / 60;
    sec = sec - 60 * min;
    hour = min / 60;
    min = min - 60 * hour;

    printf("%d hours %d minutes %d seconds", hour, min, sec);

    return 0;
}
