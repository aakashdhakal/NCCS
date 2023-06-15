#include<stdio.h>
#include<math.h>

double function(double x){
	return sin(x);
}

double differentiate(double x, double h){
	double x1 = x - h;
	double x2 = x;
	double x3 = x+h;
	double y1 = function(x1);
	double y2 = function(x2);
	double y3 = function(x3);
	
	double derivative = (y3-y1)/(2*h);
	return derivative;
}

int main(){
	double x,h;
	printf("Enter the point at which derivate is to be calculated: ");
	scanf("%lf",&x);
	printf("Enter the step size(h): ");
	scanf("%lf",&h);
	
	double derivative = differentiate(x,h);
	printf("The derivative at x = %lf is %lf\n",x,derivative);
	return 0;
}
