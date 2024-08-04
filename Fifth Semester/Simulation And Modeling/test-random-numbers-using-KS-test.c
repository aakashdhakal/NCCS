#include <conio.h>
#include <stdio.h>
#include <math.h>

#define N 5
#define Dalpha 0.665

int main()
{
    float R[N] = {0.05, 0.14, 0.44, 0.81, 0.93};
    float X[N], Y[N], Z[N];
    float D1, D2, D;
    int i;

    for (i = 0; i < N; i++)
    {
        X[i] = (float)(i + 1) / N;
        Y[i] = X[i] - R[i];
        Z[i] = R[i] - (float)i / N;
    }

    D1 = Y[0];
    for (i = 1; i < N; i++)
    {
        if (D1 < Y[i])
            D1 = Y[i];
    }

    D2 = Z[0];
    for (i = 1; i < N; i++)
    {
        if (D2 < Z[i])
            D2 = Z[i];
    }

    D = (D1 > D2) ? D1 : D2;

    printf("D = %f\n", D);

    if (D < Dalpha)
        printf("The null hypothesis is accepted.\n");
    else
        printf("The null hypothesis is rejected.\n");

    return 0;
}