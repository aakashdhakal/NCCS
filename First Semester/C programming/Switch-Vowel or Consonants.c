#include<stdio.h>
int main()
{
	char ch;
	printf("Enter any alphabet: ");
	scanf("%c", &ch);
	
	switch(ch){
		
		case'a':
		case 'A':
		case'u':
		case 'U':
		case'e':
		case 'E':
		case'i':
		case 'I':
		case'o':
		case 'O':{
			printf("%c is vowel letter", ch);
			break;
		}
		default:{
		printf("%c is consonant letter", ch);
		break;
	}
	}
	
	
}
