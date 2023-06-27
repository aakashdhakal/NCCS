#include<stdio.h>

int main(){
	int a, b, sum, difference, division, product, option;
	printf("Enter first number");
	scanf("%d", &a);
		printf("Enter second number");
	scanf("%d", &b);
	printf("What operation would you like to perform?\nPlease press\n1 for addition\n2 for subtraction\n3 for multiplication\n4 for division");
	scanf("%d", &option);
	
	
		switch (option){
			
	case 1:{
	sum = a+b;
	printf("The reqiured sum of %d and %d is %d", a, b, sum);
	break;
}
	
	case 2:{
	difference = a-b;
	printf("The difference between %d and %d is %d", a, b, difference);
	break;
	}
		case 3:{
	product = a*b;
	printf("The product of %d and %d is %d", a, b, product);
	break;
	}
		case 4:{
	division = a-b;
	printf("The quotient of %d divided by %d is %d", a, b, division);
	break;
	}
	defult:{
		printf("Invalid option");
		break;
	}
}
	return 0;
}
