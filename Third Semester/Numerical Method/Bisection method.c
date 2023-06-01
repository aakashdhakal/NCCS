#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

float f(float x)
{
    float y;
    y = pow(x, 2) + x - 2;
    return y;
}

void main()
{
    float x1, x2, x0, error = 0.0001;
    int i = 0;

    printf("\nEnter two initial guesses:");
    scanf("%f%f", &x1, &x2);

    if (f(x1) * f(x2) > 0)
    {
        printf("\nWrong Input!!");
        exit(0);
    }
    else
    {
        do
        {
            x0 = (x1 + x2) / 2;

            if (f(x0) * f(x1) > 0)
                x1 = x0;
            else
                x2 = x0;

            i++;
        } while (fabs(f(x0)) > error);
    }

    printf("\nRoot = %f", x0);
    printf("\nNumber of iterations = %d", i);

    getch();
}
