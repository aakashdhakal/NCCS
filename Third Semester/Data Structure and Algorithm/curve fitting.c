#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define error 0.001

int main()
{
    int i, n;
    float x[10], y[10], sumx = 0.0, sumy = 0.0;
    float sumxx = 0.0, sumxy = 0.0;
    float meanx, meany, denom, a, b;
    printf("HOW MANY ELEMENTS? :");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }
    for (i = 0; i < n; i++)
    {
        sumx += x[i];
        sumy += y[i];
        sumxx += x[i] * x[i];
        sumxy += x[i] * y[i];
    }
    meanx = sumx / n;
    meany = sumy / n;
    denom = n * sumxx - sumx * sumx;
    if (fabs(denom) > error)
    {
        b = (n * sumxy - sumx * sumy) / denom;
        a = meany - b * meanx;
        printf("y = %fx + %f", b, a);
    }
    else
    {
        printf("\n NO SOLUTION!!");
    }
    getch();
    return 0;
}
