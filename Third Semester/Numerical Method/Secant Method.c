
/* Program: Finding real roots of nonlinear
   equation using Secant Method
   Author: CodeSansar
   Date: November 18, 2018 */

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

/* Defining equation to be solved.
   Change this equation to solve another problem. */
#define    f(x)    x*x*x - 2*x - 5

void main()
{
	 float x0, x1, x2, f0, f1, f2, e;
	 int step = 1, N;
	 clrscr();
	 /* Inputs */
	 printf("\nEnter initial guesses:\n");
	 scanf("%f%f", &x0, &x1);
	 printf("Enter tolerable error:\n");
	 scanf("%f", &e);
	 printf("Enter maximum iteration:\n");
	 scanf("%d", &N);
	
	 /* Implementing Secant Method */
	 printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
	 do
	 {
		  f0 = f(x0);
		  f1 = f(x1);
		  if(f0 == f1)
		  {
			   printf("Mathematical Error.");
			   exit(0);
		  }
		  
		  x2 = x1 - (x1 - x0) * f1/(f1-f0);
		  f2 = f(x2);
		  
		  printf("%d\t\t%f\t%f\t%f\t%f\n",step,x0,x1,x2, f2);
		  
		  x0 = x1;
		  f0 = f1;
		  x1 = x2;
		  f1 = f2;
		  
		  step = step + 1;
		  
		  if(step > N)
		  {
			   printf("Not Convergent.");
			   exit(0);
		  }
	 }while(fabs(f2)>e);
	
	 printf("\nRoot is: %f", x2);
	 getch();
}
