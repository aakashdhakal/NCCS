#include<stdio.h>

int sum(int *A[4],int *B[4]){
	int sum,i,j;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			sum = *A[i] + *B[j];
		}
	}
	
}

int main(){
	int A[4],B[4],i,j;
	printf("Enter the value of array A: ");
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			scanf("%d", &A[i]);
		}
	}
	printf("Enter the value of array B: ");
		for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			scanf("%d", &A[i]);
		}
	}
	sum(&A,&B);
}

