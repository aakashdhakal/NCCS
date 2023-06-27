#include<stdio.h>
#include<math.h>
int main()
{
	int a, b, c, T;
	printf("Enter three numbers a, b, c\n");
	scanf("%d %d %d",&a, &b, &c);
	if(b < 0){
		printf("ERROR: Please enter any positive number");
	}
	else{
	T = 2*a + sqrt(b) + 9*c;
	printf("The required solution of the equation is %d", T);
}
	return 0;
}
