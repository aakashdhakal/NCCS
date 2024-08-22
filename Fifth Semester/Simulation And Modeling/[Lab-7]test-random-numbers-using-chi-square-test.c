#include <stdio.h>
#include <conio.h>
#define N 100
#define alpha 16.9
void sort(float arr[]);
int main()
{
    int i, j;
    float XO[10];
    float XE[10];
    float XOE[10];
    float XOE2[10];
    float R[10];
    float s = 0.0;
    float x[] = {0.34, 0.83, 0.96, 0.47, 0.79, 0.37, 0.99, 0.37, 0.72, 0.06, 0.18, 0.90,
                 0.76, 0.99, 0.30, 0.71, 0.17, 0.51, 0.43, 0.39, 0.26, 0.25, 0.79,
                 0.77, 0.17, 0.23, 0.99, 0.54, 0.56, 0.84, 0.97, 0.89, 0.64, 0.67,
                 0.82, 0.19, 0.46, 0.01, 0.97, 0.24, 0.88, 0.87, 0.70, 0.56, 0.56,
                 0.82, 0.05, 0.81, 0.30, 0.40, 0.64, 0.44, 0.81, 0.41, 0.05, 0.93,
                 0.66, 0.028, 0.94, 0.64, 0.47, 0.12, 0.94, 0.52, 0.45, 0.65, 0.10,
                 0.69, 0.96, 0.40, 0.60, 0.21, 0.74, 0.73, 0.31, 0.37, 0.42, 0.34,
                 0.58, 0.19, 0.11, 0.46, 0.22, 0.99, 0.78, 0.39, 0.18, 0.75, 0.73, 0.79,
                 0.29, 0.67, 0.74, 0.02, 0.05, 0.42, 0.49, 0.49, 0.05, 0.62, 0.78};
    sort(x);
    for (i = 0; i < 10; i++)
    {
        XO[i] = 0.0;
        XE[i] = 10.0;
    }
    for (i = 0; i < N; i++)
    {
        if (x[i] <= 0.1)
            XO[0]++;
        else if (x[i] <= 0.2)
            XO[1]++;
        else if (x[i] <= 0.3)
            XO[2]++;
        else if (x[i] <= 0.4)
            XO[3]++;
        else if (x[i] <= 0.5)
            XO[4]++;
        else if (x[i] <= 0.6)
            XO[5]++;
        else if (x[i] <= 0.7)
            XO[6]++;
        else if (x[i] <= 0.8)
            XO[7]++;
        else if (x[i] <= 0.9)
            XO[8]++;
        else if (x[i] <= 1.0)
            XO[9]++;
    }

    for (i = 0; i < 10; i++)
    {
        XOE[i] = XO[i] - XE[i];
        XOE2[i] = XOE[i] * XOE[i];
        R[i] = XOE2[i] / XE[i];
        s = s + R[i];
    }
    printf("s =  %0.2f\n", s);
    printf("Alpha at  5%% level of significance for n=9 is %0.2f\n", alpha);
    if (s <= alpha)
        printf("Accepted");
    else
        printf("Rejected");
}
void sort(float x[])
{

    int i, j;
    float temp;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N - 1; j++)
        {
            if (x[j + 1] < x[j])
            {
                temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }
}
