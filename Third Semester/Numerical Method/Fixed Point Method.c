
#include <stdio.h>
#include <conio.h>
#include <math.h>

float f(float x)
{
	return (sin(x) - 5 * x + 2);
}

float g(float x)
{
	return ((sin(x) + 2) / 5);
}

int main()
{
	int step = 1;
	float x0, x1, e;
	printf("Enter initial guess: ");
	scanf("%f", &x0);
	printf("Enter tolerable error: ");
	scanf("%f", &e);

	printf("\n\tStep\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
	do
	{
		x1 = g(x0);
		printf("\t%d\t%f\t%f\t%f\t%f\n", step, x0, f(x0), x1, f(x1));

		step = step + 1;
		x0 = x1;

	} while (fabs(f(x1)) > e);

	printf("\nRoot is %f", x1);

	getch();
	return 0;
}
