#include <stdio.h>

void cross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    int x_cross, y_cross;
    int t;
    int k1, k2;
    int b1, b2;

    if (x1 >= x2)
    {
        t = x1;
        x1 = x2;
        x2 = t;
        t = y1;
        y1 = y2;
        y2 = t;
    }

    if (x3 >= x4)
    {
        t = x3;
        x3 = x4;
        x4 = t;
        t = y3;
        y3 = y4;
        y4 = t;
    }

    //Оба вертикальны
    if (x1 == x2 && x3 == x4)
        printf("There is no cross. Result: %d", 0);
    else
    {

        //Первый вертикальный
        if (x1 == x2)
        {
            x_cross = x1;

            if (y3 == y4)
                k2 = 0;
            else
                k2 = (y4 - y3) / (x4 - x3);

            b2 = y3 - k2 * x3;
            y_cross = k2 * x_cross + b2;

            if (x_cross >= x3 && x_cross <= x4 && ((y_cross >= y1 && y_cross <= y2) || (y_cross >= y2 && y_cross <= y1)))
                printf("There is cross. Result: %d", 1);
            else
                printf("There is no cross. Result: %d", 0);
        }
        else
        {
            //Второй вертикальный
            if (x3 == x4)
            {
                x_cross = x3;

                if (y1 == y2)
                    k1 = 0;
                else
                    k1 = (y2 - y1) / (x2 - x1);

                b1 = y1 - k1 * x1;
                y_cross = k1 * x_cross + b1;

                if (x_cross >= x1 && x_cross <= x2 && ((y_cross >= y3 && y_cross <= y4) || (y_cross >= y4 && y_cross <= y3)))
                    printf("There is cross. Result: %d", 1);
                else
                    printf("There is no cross. Result: %d", 0);
            }
            //Общий случай
            else
            {
                if (y1 == y2)
                    k1 = 0;
                else
                    k1 = (y2 - y1) / (x2 - x1);

                if (y3 == y4)
                    k2 = 0;
                else
                    k2 = (y4 - y3) / (x4 - x3);

                //Проверка на параллельность
                if (k1 == k2)
                {
                    printf("Parallel. Result: %d", 0);
                }
                //Общий случай
                else
                {
                    b1 = y1 - k1 * x1;
                    b2 = y3 - k2 * x3;

                    x_cross = (b2 - b1) / (k1 - k2);

                    if (x_cross >= x1 && x_cross <= x2 && x_cross >= x3 && x_cross <= x4)
                        printf("There is cross. Result: %d", 1);
                    else
                        printf("There is no cross. Result: %d", 0);
                }
            }
        }
    }
}

int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4;

    //Ввод данных
    printf("Enter coordinates for four points:\n");
    int ch = scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

    if (ch != 8)
    {
        printf("Incorrect enter.");
        return 1;
    }
    else
    {
        if ((x1 == x2 && y1 == y2) || (x3 == x4 && y3 == y4))
        {
            printf("Incorrect enter.");
            return 1;
        }
        else
            cross(x1, y1, x2, y2, x3, y3, x4, y4);
    }

    return 0;
}
