#include<stdio.h>

 void compare(int a,int b){
	if(a>b){
		printf("%d is greater", a);
	}
	else if(a == b){
		printf("%d is equal to %d", a,b);
	}
	else{
		printf("%d is greater", b);
	}

}
int main(){
	int a, b;
	printf("Enter two numbers: ");
	scanf("%d\t%d",&a,&b);
	compare(a, b);
	return 0;
}