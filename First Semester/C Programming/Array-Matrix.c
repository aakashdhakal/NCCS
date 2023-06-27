#include<stdio.h>

int main(){
	int a[4][4], t[4][4], i, j;
				printf("Enter the content of the matrix A: ");
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){

			scanf("%d", &a[i][j]);
		}
		printf("\n");
	}
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			t[j][i] = a[i][j];
		
			
		printf("\n");
	}		
} 

for(i=0; i<4; i++){
		for(j=0; j<4; j++){

			printf("%d\t", t[i][j]);
		
		}
		printf("\n");
	}
}
	