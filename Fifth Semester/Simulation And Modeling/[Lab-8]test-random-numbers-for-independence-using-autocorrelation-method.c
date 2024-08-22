#define N 30
#include <stdio.h>
#include <math.h>
int main()
{
    int i, m, M, k;
    i = 2, m = 5;
    M = ((N - i) / m) - 1;
    float s35 = 0, r35, z0;
    float R[] = {0.12, 0.01, 0.23, 0.28, 0.89, 0.31, 0.64, 0.28, 0.83, 0.93, 0.99,
                 0.15, 0.33, 0.35, 0.91, 0.41, 0.60, 0.27, 0.75, 0.88, 0.68, 0.49, 0.05, 0.43, 0.95,
                 0.58, 0.19, 0.36, 0.69, 0.87};
    for (k = 0; k <= M; k++)
    {
        s35 = s35 + R[i + k * m] * R[i + (k + 1) * m];
    }
    s35 = s35 / (M + 1);
    s35 = s35 - 0.25;
    r35 = sqrt(13 * M + 7) / (12 * (M + 1));

    z0 = r35 / s35;
    printf("The null hypothesis that numbers are independent is %s\n", (z0 <= 1.96) ? "accepted" : "not accepted");
    return 0;
}
