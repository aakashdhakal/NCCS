#include<stdio.h>
int main(){
	char input;
	printf("Enter the character: ");
	scanf("%c", &input);
	
	if(input >= 'A' && input <= 'Z'){
		printf("%c is a capital letter", input);
	}
	else if(input >= 'a' && input <= 'a'){
			printf("%c is a small letter", input);
	}
		else if(input >= '0' && input <= '9'){
			printf("%c is a digits", input);
	}
		else{
			printf("%c is a special character", input);
	}
}
