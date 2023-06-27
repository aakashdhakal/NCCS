#include<stdio.h>

void sum(int *A, int *B){
	int sum;
	sum = *A +*B;
	printf("The sum of %d and %d is %d", *A,*B,sum);
	return 0;
}

int main(){
	int A,B;
	printf("Enter the first number A: ");
	scanf("%d", &A);
	printf("Enter the second number B: ");
	scanf("%d", &B);
	sum(&A,&B);
}

