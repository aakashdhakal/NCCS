#include<stdio.h>

#define TSIZE 10

void linear_probe(int *arr ,int key){
	int i,j,h;
	h = key%TSIZE;
	if(arr[h] == -1){
		arr[h] = key;
	}
	else{
		j=1;
		while(arr[h] != -1){
			h = (h+i)%TSIZE;
			
		}
		arr[h] = key;
	}
	
}

void quadratic_probe(int *arr, int key){
	int i,j,h;
	h = key%TSIZE;
	if(arr[h] == -1){
		arr[h] = key;
	}
	else{
		j=1;
		while(arr[h] != -1){
			h = (h+i*i)%TSIZE;
			
		}
		arr[h] = key;
	}
	
}

int main(){
	int htable[TSIZE];
	int i,j ;
	for(i=0;i<TSIZE;i++){
		htable[i] = -1;
	}
	int arr[TSIZE] = {97,79,77,13,23,33,11,15};
	
	printf("Using linear probing\n");
	
	for(i=0;i<TSIZE;i++){
		linear_probe(htable,arr[i]);
		printf("htable[%d] = %d\n",i,htable[i]);
	}
	
	printf("\nUsing quadratic probing\n");
	
	for(i=0;i<TSIZE;i++){
		quadratic_probe(htable,arr[i]);
		printf("htable[%d] = %d\n",i,htable[i]);
	}
	return 0;
}