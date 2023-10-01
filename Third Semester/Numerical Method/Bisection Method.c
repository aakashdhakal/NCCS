#include <stdio.h>
#include <conio.h>
#include <math.h>

// यो भित्र को function कृपया change गर्दिनु होला !! धन्यबाद !!
float f(float x)
{
    return exp(x) - 3 * x;
}

void main()
{
    float x0, x1, x2, f0, f1, f2, e, E;
    int step = 1;
    do
    {
        printf("\nEnter two initial guesses [a,b]: ");
        scanf("%f%f", &x0, &x1);
        if (f0 * f1 > 0.0)
        {
            printf("Incorrect Initial Guesses.\n");
        }
    } while (f0 * f1 > 0.0);
    printf("Enter tolerable error: ");
    scanf("%f", &e);
    f0 = f(x0);
    f1 = f(x1);

    printf("\n\tStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do
    {
        x2 = (x0 + x1) / 2;
        f2 = f(x2);
        E = fabs((x1 - x0) / x1);

        printf("\t%d\t\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);

        if (f2 < 0)
        {
            x0 = x2;
        }
        else
        {
            x1 = x2;
        }
        step = step + 1;
    } while (E > e);
    printf("\nRoot is: %f", x2);
    getch();
}
