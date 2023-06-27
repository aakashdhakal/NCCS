#include<stdio.h>

int main()
{
	int n,d,sum = 0,a;

	printf("Enter the number: ");
	scanf("%d",&n);
		a = n;

	while(n!=0) {
		d = n%10;
		sum  += d*d*d;
		n = n/10;
	}

	if(a == sum) {
		printf("%d is a armstrong number",n);
	} else {
		printf("%d is not a armstrong number",n);
	}
	return 0;
}