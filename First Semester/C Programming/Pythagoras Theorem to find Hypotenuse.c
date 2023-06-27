#include<stdio.h>
#include<math.h>

int main(){
	float p, b, h;
	printf("Please enter the value of perpendicular of the triangle: ");
	scanf("%f", &p);
	printf("Please enter the value of base of the triangle: ");
	scanf("%f", &b);
	h = sqrt(pow(p,2) + pow(b,2));
	printf("The hypotenuse of triangle having perpendicular %fcm and base %fcm is %fcm", p, b, h);
	return 0;

}
