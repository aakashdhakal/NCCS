#include<stdio.h>
#include<conio.h>
#include<math.h>

int main(){
	int numA[8], numB[8], diff[8];
	int i,n=3;
	printf("Enter first number: ");
	for(i=0;i<=n;i++){
		scanf("%d", &numA[i]);
	}
	printf("Enter second number: ");
	for(i=0;i<=n;i++){
		scanf("%d", &numB[i]);
	}
	for(i=3;i>=0;i--){
		diff[i] = numA[i]-numB[i];
		if(diff[i]<0){
			numA[i-1] = numA[i-1]-1;
		}
		diff[i] = fabs(diff[i]%2);
	}
	printf("\n Difference is: ");
	for(i=0;i<=n;i++){
		printf("%d",diff[i]);
	}
	
	return 0;
	
}