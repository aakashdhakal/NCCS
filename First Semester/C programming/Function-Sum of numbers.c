#include<stdio.h>
int main()
{
	int a, b, c, large, small;
	printf("Enter first number: ");
	scanf("%d",&a);
	printf("Enter second number: ");
	scanf("%d",&b);
	printf("Enter third number: ");
	scanf("%d",&c);
	
	if(a>b && a>c){
		printf("%d is the largest number\n",a);
		large = a;
		}
	else if(b>a && b>c){
		printf("%d is the largest number\n",b);
		large = b;
	}
	else{
		printf("%d is the largest number\n",c);
		large = c;
	}
	
	
	
	if(a<b && a<c){
		printf("%d is the smallest number\n",a);
		small = a;
		}
	else if(b<a && b<c){
		printf("%d is the smallest number\n",b);
		small = a;

	}
	else{
		printf("%d is the smallest number\n",c);
		small = a;
	}
	
	if(large%2 == 0){
		printf("%d is even\n",large);
	}
	else{
		printf("%d is odd\n",large);
	}
	
		if(small%2 == 0){
		printf("%d is even\n",small);
	}
	else{
		printf("%d is odd\n",small);
	}
	return 0;
}
