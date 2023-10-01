#include <stdio.h>
#include <conio.h>
#include <math.h>

// यो भित्र को function कृपया change गर्दिनु होला !! धन्यबाद !!
float f(float x)
{
    return pow(x - 2, 2) - log10(x);
}

int main()
{
    float x0, x1, x2, f0, f1, f2, e, E;
    int step = 1, N;

    printf("\nEnter initial guesses: ");
    scanf("%f%f", &x0, &x1);
    printf("Enter tolerable error: ");
    scanf("%f", &e);

    printf("\n\tStep\t\tx0\t\tx1\t\tf(x0)\t\tf(x1)\t\tx2\n");
    do
    {
        f0 = f(x0);
        f1 = f(x1);
        if (f0 == f1)
        {
            printf("Mathematical Error.");
            return 0;
        }

        x2 = (x0 * f1 - x1 * f0) / (f1 - f0);

        E = fabs((x2 - x1) / x2);

        printf("\t%d\t\t%f\t%f\t%f\t%f\t%f\n", step, x0, x1, f0, f1, x2);

        x0 = x1;
        x1 = x2;

        step = step + 1;

    } while (E > e);

    printf("\nRoot is: %f", x2);
    getch();
}
