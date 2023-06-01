#include <stdio.h>
#include <conio.h>
#include <math.h>

float f(float x)
{
    float y;
    y = pow(x, 2) + x - 2;
    return y;
}

float fd(float x)
{
    float y;
    y = 2 * x + 1;
    return y;
}

void main()
{
    float x0, x1, error = 0.0001;
    int i = 0;

    printf("\nGuess initial root:");
    scanf("%f", &x1);

    do
    {
        x0 = x1 - (f(x1) / fd(x1));
        x1 = x0;
        i++;
    } while (fabs(f(x0)) > error);

    printf("\nRoot = %f", x0);
    printf("\nNumber of iterations = %d", i);

    getch();
}
