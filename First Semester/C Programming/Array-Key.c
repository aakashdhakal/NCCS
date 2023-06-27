#include<stdio.h>

void sequentialsearch(int b[10],int size, int key){
	int i,largest=b[0];
	for(i=0; i<size; i++){
		if(b[i]==key){
			printf("key found in position index %d",i);
			break;
		}

		}
			for (i=1;i<size; i++){
		if(b[i]>largest){
			largest=b[i];
		}
	}
			if(i==size){
			printf("key not found");
			printf("The largest number is %d", largest);
	}
}
int main(){
	int key, a[10]={50, 60, 40, 30, 100, 5, 10, 15, 90, 20};
	
	printf("Enter any key ko search: ");
	scanf("%d", &key);
	sequentialsearch(a, 10, key);
	return 0;
}
