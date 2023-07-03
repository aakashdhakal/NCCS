#include<stdio.h>
#include<conio.h>
#include<math.h>

/* Define function here */
double f(double x){
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
 do{
 printf("Enter number of sub intervals: ");
 scanf("%d", &subInterval);
 if(subInterval%2 != 0){
 	printf("\nThe subintervals should be even\n");
 }
}
 while(subInterval%2 != 0);
 

 /* Calculation */
 /* Finding step size */
 stepSize = (upper - lower)/subInterval;

 /* Finding Integration Value */
 integration = f(lower) + f(upper);
 for(i=1; i<= subInterval-1; i++)
 {
  k = lower + i*stepSize;
  if(i%2==0)
  {
   integration = integration + 2 * f(k);
  }
  else
  {
   integration = integration + 4 * f(k);
  }
 }
 integration = integration * stepSize/3;
 printf("\nRequired value of integration is: %.3f", integration);
 getch();
 return 0;

}
