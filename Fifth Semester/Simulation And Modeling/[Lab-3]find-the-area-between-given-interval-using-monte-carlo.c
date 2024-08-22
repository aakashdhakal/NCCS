#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define F(x) (x * x)
#define xl 1
#define yl 1
#define xu 2
#define yu 4
#define N 10000
int main()
{
    int xran, yran, n = 0, a = 1, b = 2, c = 4, i;
    float area;
    srand(time(0));
    for (i = 1; i <= N; i++)
    {
        xran = (rand() % (xu - xl + 1)) + xl;
        yran = (rand() % (yu - yl + 1)) + yl;
        if (xran * xran <= yran)
            n++;
    }
    printf("Number of points =  %d\n", n);
    area = c * (b - a) * (float)n / N;
    printf("The area =  %f", area);
    return 0;
}
