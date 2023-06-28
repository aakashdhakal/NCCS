#include<stdio.h>
#include<conio.h>

void TowerOfHanoi(char,char,char,int);

int main(){
	int n;
	printf("Enter the number of disks: ");
	scanf("%d",&n);
	TowerOfHanoi('A','B','C',n);
}

void TowerOfHanoi(char from,char other, char to,int n){

	if(n==1)
		printf("\nMOVE DISK FROM %c TO %c",from,to);
	else{
		TowerOfHanoi(from,to,other,n-1);
		printf("\nMOVE DISK FROM %c TO %c",from,to);
		TowerOfHanoi(other,from,to,n-1);
	}	
}
