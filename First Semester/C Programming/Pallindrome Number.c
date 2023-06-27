#include<stdio.h>

int main()
{
	int n,d,sum = 0,a,r=0;

	printf("Enter the number: ");
	scanf("%d",&n);
		a = n;

	while(n!=0) {
		d = n%10;
		r = r*10+d;
		n = n/10;
	}

	if(a == r) {
		printf("%d is a pallindrome number",n);
	} else {
		printf("%d is not a pallindrome number",n);
	}
	return 0;
}