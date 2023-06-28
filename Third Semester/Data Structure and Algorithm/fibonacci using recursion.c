#include<stdio.h>
#include<conio.h>

int fib(int n){
	if(n == 0){
		return 0;
	}
	else if(n == 1){
		return 1;
	}
	else{
		return (fib(n-1) + fib(n-2));
	}
}
int main(){
	int n;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	printf("The required term of fibonacci sequence = %d", fib(n));
}