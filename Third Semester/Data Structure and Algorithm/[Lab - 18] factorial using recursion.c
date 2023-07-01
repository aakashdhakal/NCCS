#include<stdio.h>
#include<conio.h>

int factorial(int);

int main(){
	int fact,a;
	do{
	printf("\nEnter the number: ");
	scanf("%d", &a);
	if(a<0){
		printf("Invalid Input\n");
	}
}while(a < 0);
	printf("The factorial of %d is %d", a, factorial(a));
}

int factorial(int a){
	if(a == 0){
		return 1;
	}
	else{
		return  a*factorial(a-1);
	}
}
