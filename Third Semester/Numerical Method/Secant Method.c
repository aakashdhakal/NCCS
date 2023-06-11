#include <stdio.h>
#include <conio.h>
#include <math.h>

float f(float x)
{
	return (pow(x, 2) - 4 * x - 10);
}

void main()
{
	float x0, x1, x2, f0, f1, f2, e;
	int step = 1, N;

	printf("\nEnter initial guesses: ");
	scanf("%f%f", &x0, &x1);
	printf("Enter tolerable error: ");
	scanf("%f", &e);
	printf("Enter maximum iteration: ");
	scanf("%d", &N);

	printf("\n\tStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
	do
	{
		f0 = f(x0);
		f1 = f(x1);
		if (f0 == f1)
		{
			printf("Mathematical Error.");
			return 0;
		}

		x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
		f2 = f(x2);

		printf("\t%d\t\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);

		x0 = x1;
		f0 = f1;
		x1 = x2;
		f1 = f2;

		step = step + 1;

		if (step > N)
		{
			printf("Not Convergent.");
			return 0;
		}
	} while (fabs(f2) > e);

	printf("\nRoot is: %f", x2);
	getch();
}
