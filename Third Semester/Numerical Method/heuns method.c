#include<stdio.h>

float f(float x,float y){
	return 2*y/x;
}
int main()
{
float x,y,h,xn,l;
printf("Enter value for x and y: ");
scanf("%f%f",&x,&y);
printf("Enter value for h and last of x: ");
scanf("%f%f",&h,&xn);
while(x+h<=xn)
{
l=(h/2)*(f(x,y)+f(x+h,y+h*f(x,y)));
y=y+l;
x=x+h;

printf("y = %f\tx = %f\n",y,x);
}
}