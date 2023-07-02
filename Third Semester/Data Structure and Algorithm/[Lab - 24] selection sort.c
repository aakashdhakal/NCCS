#include<stdio.h>


void selectionSort(int number[], int n){
	int i,j,temp,si;
	for(i=0;i<n-1;i++){
		si = i;
		for(j=i+1;j<n;j++){
			if(number[si]>number[j]){
				si = j;
			}
		}
			if(si != i){
				temp = number[i];
				number[i] = number[si];
				number[si] = temp;
		}
	}
	printf("The numbers after sorting: ");
	for(i=0;i<n;i++){
		printf("%d\t",number[i]);
	}
}

int main(){
	int n;
	printf("Enter the total no. of elements: ");
	scanf("%d",&n);
	int numbers[n],i;
	printf("Enter %d numbers\n ");
	for(i=0;i<n;i++){
		scanf("%d",&numbers[i]);
	}
	printf("The numbers before sorting: ");
	for(i=0;i<n;i++){
		printf("%d\t",numbers[i]);
	}
	printf("\n");
	selectionSort(numbers,n);

}
