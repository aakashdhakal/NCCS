
#include<stdio.h>
#include<conio.h>
#include<math.h>

// यो भित्र को function कृपया change गर्दिनु होला !! धन्यबाद !!double f(double x){
double f(double x)
	return pow(x,2)+ 2*x;
}

int main()
{
 float lower, upper, integration=0.0, stepSize, k;
 int i, subInterval;

 /* Input */
 printf("Enter lower limit of integration: ");
 scanf("%f", &lower);
 printf("Enter upper limit of integration: ");
 scanf("%f", &upper);
 printf("Enter number of sub intervals: ");
 scanf("%d", &subInterval);

 /* Calculation */
 /* Finding step size */
 stepSize = (upper - lower)/subInterval;

 /* Finding Integration Value */
 integration = f(lower) + f(upper);
 for(i=1; i<= subInterval-1; i++)
 {
  k = lower + i*stepSize;
  integration = integration + 2 * f(k);
 }
 integration = integration * stepSize/2;
 printf("\nRequired value of integration is: %.3f", integration);
 getch();
 return 0;
}
