#include <stdio.h>
#include <math.h>

#define N 5
#define Dalpha 0.665

int main()
{
    float R[N] = {0.05, 0.14, 0.44, 0.81, 0.93};
    float D1 = 0, D2 = 0, D;

    for (int i = 0; i < N; i++)
    {
        float X = (float)(i + 1) / N;
        D1 = fmax(D1, X - R[i]);
        D2 = fmax(D2, R[i] - (float)i / N);
    }

    D = fmax(D1, D2);

    printf("D = %f\n", D);
    printf("The null hypothesis is %s.\n", (D < Dalpha) ? "accepted" : "rejected");

    return 0;
}