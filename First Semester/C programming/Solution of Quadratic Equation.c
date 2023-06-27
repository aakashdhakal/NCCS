#include<stdio.h>
#include<math.h>

int main(){
	int a,b,c;
	float x1,x2;
	printf("Enter the value of a\t");
	scanf("%d", &a);
	printf("Enter the value of b\t");
	scanf("%d", &b);
	printf("Enter the value of c\t");
	scanf("%d", &c);

	
	if(b*b-4*a*c < 0){
		printf("Math Error!\nThe number inside square root is negative\nPlease input valid number");
		return 0;
	}
	else{
			x1 = (-b+sqrt(b*b-4*a*c))/2*a;
			x2 = (-b-sqrt(b*b-4*a*c))/2*a;
		printf("The solution of the equation %dX^2 + %dX + %d is X1= %f and X2= %f",a,b,c,x1,x2);
		return 0;
	}
	
	
}
