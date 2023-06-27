#include<stdio.h>


int main(){
	char name[20];
	int marks, Total;
	printf("Enter the name of the student\t");
	scanf("%[^\n]s",&name);
	printf("Enter the marks obtained\t");
	scanf("%d",&marks);
	if(100>=marks && marks>=90){
		printf("Congratulation! You got A+ grade", name);
	}
	else if(90>=marks && marks>=80){
		printf("Congratulation! %s got A grade", name);
	}
	else if(80 >=marks && marks>=70){
		printf("Congratulation! %s got B+ grade", name);
	}
				else if(70>=marks && marks>=60){
		printf("Congratulation! %s got B grade", name);
	}
							else if(60>=marks && marks>=50){
		printf("Congratulation! %s got C grade", name);
	}
							else if(marks < 50 ){
		printf("%s have failed in the examination", name);
	}
		else if(marks > 100 ){
		printf("ERROR! You enter invalid marks");
	}
		
	return 0;
}
