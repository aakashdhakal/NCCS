#include<stdio.h>
#include<math.h>

int main(){
	int x =30;
	const float PI = 3.14;
	float r, sine;
	printf("Please enter the required value of angle: ");
	scanf("%d", &x);
	r = x*(PI/180);
	sine = sin(r);
	printf("sin(%d) = %f", x, sine);
	return 0;
}
