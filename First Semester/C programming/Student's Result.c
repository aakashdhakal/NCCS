#include<stdio.h>
int main()
{
	char name[20];
	int Physics, Math, DigitalLogic, C_programming, IIT, Total;
	float percentage;
	printf("Enter the name of the student\t");
	scanf("%[^\n]s",&name);
	printf("Enter the marks in Physics\t");
	scanf("%d",&Physics);
	printf("Enter the marks in Math\t");
	scanf("%d",&Math);
	printf("Enter the marks in Digital Logic\t");
	scanf("%d",&DigitalLogic);
	printf("Enter the marks in C Programming\t");
	scanf("%d",&C_programming);
	printf("Enter the marks in Introduction to Information Technology(IIT)\t");
	scanf("%d",&IIT);
	Total = Physics + Math + DigitalLogic + C_programming + IIT;
	percentage = (Total/500.0)*100;
	printf("Mr/Ms %s has scored %f percent in the examination\n", name, percentage);
	
	
	if(percentage > 80){
		printf("Congratulation! You have passed with distinction");
	}
	else if(80 >percentage && percentage>60){
		printf("Congratulation! You have passed with first division");
	}
				else if(60>percentage && percentage>45){
		printf("Congratulation! You have passed with second division");
	}
							else if(45>percentage && percentage>35){
		printf("Congratulation! You have passed with third division");
	}
							else if(percentage < 35 ){
		printf("You have failed in the examination");
	}
		
	return 0;
}
