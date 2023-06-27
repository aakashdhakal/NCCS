#include<stdio.h>

int A[4][4] = {{3,6,9,10},{12,1,2,50},{11,50,7,8},{13,10,8,9}},
	B[4][4] = {{10,20,30,40},{50,60,70,80},{90,100,110,120},{130,140,150,160}},
	sum[4][4],diff[4][4],i,j;
	
 void add(){
 	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			sum[i][j] = A[i][j] + B[i][j];
			printf("%d\t", sum[i][j]);
			}
					printf("\n");
	}
	
}
void sub(){
 	for(i=0;i<4;i++)
	
        {
		for(j=0;j<4;j++){
			diff[i][j] = A[i][j] - B[i][j];
			printf("%d\t", diff[i][j]);
		}
		printf("\n");
	}
}


int main(){
	
	 int option;
	 
	 printf("Enter 1 for addition or 2 for subtraction: ");
	 scanf("%d", &option);
	 
	 switch(option){
	 	
	 	case 1:{
	 		add();
			break;
		 }
		 
		 	case 2:{
	 		sub();
			break;
		 }
	 }
}
