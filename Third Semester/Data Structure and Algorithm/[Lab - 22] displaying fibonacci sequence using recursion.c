#include<stdio.h>

int fibonacci(int);

int main(){
	int c = 0,n,i;
	printf("Enter the no. of elements to be displayed: ");
	scanf("%d",&n);
	printf("The elements in fibonacci sequence are: ");
	for(i=0;i<n;i++){
		printf("%d, ",fibonacci(c));
		c++;
	}
}

int fibonacci(int n){
   if ( n == 0 )
      return 0;
   else if ( n == 1 )
      return 1;
   else
      return ( fibonacci(n-1) + fibonacci(n-2) );
} 
