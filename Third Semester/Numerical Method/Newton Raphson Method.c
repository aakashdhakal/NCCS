#include <stdio.h>
#include <conio.h>
#include <math.h>

// यो भित्र को function कृपया change गर्दिनु होला !! धन्यबाद !!
float f(float x)
{
    return x * log10(x) - 1.2;
}

float g(float x)
{
    return 1 / log(10) + log10(x);
}

int main()
{
    float x0, x1, f0, f1, g0, e, E;
    int step = 1;

    printf("\nEnter initial guess: ");
    scanf("%f", &x0);

    printf("Enter tolerable error: ");
    scanf("%f", &e);

    printf("\n\tStep\t\tx0\t\tf(x0)\t\tg(x0)\t\tx1\n");

    do
    {
        g0 = g(x0);
        f0 = f(x0);

        if (g0 == 0.0)
        {
            printf("Mathematical Error.");
            return 0;
        }

        x1 = x0 - f0 / g0;
        E = fabs((x1 - x0) / x1);

        printf("\t%d\t\t%f\t%f\t%f\t%f\n", step, x0, f0, g0, x1);

        x0 = x1;
        step = step + 1;

    } while (E > e);

    printf("\nRoot is: %f", x1);
    getch();
    return 0;
}
