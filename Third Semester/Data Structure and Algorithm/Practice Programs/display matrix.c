#include<stdio.h>
#include<stdlib.h>

int main(){
	int rows,cols,i,j;
	
	printf("Enter the order of matrix(row & column): ");
	scanf("%d%d", &rows,&cols);
	
	int **matrix = (int**)malloc(rows*sizeof(int*));
	
	for(i=0;i<rows;i++){
		matrix[i] = (int*)malloc(cols*sizeof(int));
	}
	printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display the matrix
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
	