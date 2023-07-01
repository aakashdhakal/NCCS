#include<stdio.h>
#include<conio.h>

int gcd(int,int);

int main(){
	int a,b,g;
	do{
	printf("\nEnter two numbers to find gcd: ");
	scanf("%d%d",&a,&b);
	if((a == 0 && b == 0) || (a<0 || b<0)){
		printf("Invalid Input\n");
	}

	}while((a == 0 && b == 0) || (a<0 || b<0));
	g = gcd(a,b);
	printf("GCD(%d , %d) = %d", a,b,g);
	return 0;
}

int gcd(int a,int b){
	if(b == 0){
		return a;
	}
	else{
		return gcd(b,a%b);
	}
}
