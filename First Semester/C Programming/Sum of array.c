#include<stdio.h>

int A[10];

void display(){
	int sum=0,i;
	for(i=0;i<10; i++){
		printf("%d\t",A[i]);
		sum=sum+A[i];
	}
	printf("sum = %d", sum);
}
int main(){
	int i;
	
	for(i=0; i<10; i++){
		printf("Enter A[%d]: ",i);
		scanf("%d", &A[i]);
	}
	display();
	return 0;
}

