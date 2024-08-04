#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x0, x, a, c, M = 101;
    x0 = 31, a = 17, c = 13;
    double r;
    for (int i = 1; i <= 15; i++)
    {
        x = (a * x0 + c) % M;
        r = (double)x / M;
        printf("%f\n", r);
        x0 = x;
    }
}
