#include <stdio.h>
#include "my_func.h"

int main()
{
    //char buf1[30];//, buf2[30];
    int ch1, ch2;
    char *buf1 = NULL, *buf2 = NULL;

    ch1 = snprintf(buf1, 0, "%s %o", "hello", 36);
    ch2 = my_snprintf(buf2, 0, "%s %o", "hello", 36);

//    ch = snprintf(buf1, 2, "%y %s %o!", 23, "World", 2022);
//    printf("ch = %d\n%s\n", ch, buf1);

    printf("%d\n%d", ch1, ch2);
    printf("%s\n%s", buf1, buf2);

//    ch = my_snprintf(buf2, 20, "%x %s %o!", "World", 2022);
//    printf("ch = %d\n%s\n", ch, buf2);

    return 0;
}
