
#include <stdio.h>
#include <conio.h>
#include <math.h>

// यो भित्र को function कृपया change गर्दिनु होला !! धन्यबाद !!
float f(float x)
{
    return x * exp(x) - 1;
}

float g(float x)
{
    return 1 / exp(x);
}

int main()
{
    int step = 1;
    float x0, x1, e, E;
    printf("Enter initial guess: ");
    scanf("%f", &x0);
    printf("Enter tolerable error: ");
    scanf("%f", &e);

    printf("\n\tStep\t  x0\t\t  x1\n");
    do
    {
        x1 = g(x0);
        printf("\t%d\t%f\t%f\n", step, x0, x1);
        E = fabs((x1 - x0) / x1);
        step = step + 1;
        x0 = x1;

    } while (E > e);

    printf("\nRoot is %f", x1);

    getch();
    return 0;
}
