#include<stdio.h>

int main(){
	int a, b, c;
	printf("Please enter the value of 'a'  ");
	scanf("%d", &a);
	printf("Please enter the value of 'b'  ");
	scanf("%d", &b);
	printf("The value of a is %d and value of b is %d before swapping", a, b);
	c = a;
	a = b;
	b = c;
	printf("\nThe value of a is %d and value of b is %d after swapping", a, b);
	return 0;
	
}
