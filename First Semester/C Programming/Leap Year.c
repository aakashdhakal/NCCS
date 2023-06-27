//WAP to check the given year is leap year or not

#include<stdio.h>

int main(){
	
	int year;
	
	printf("Enter the year: ");
	scanf("%d", &year);
	if(year%4 == 0 ){
		if(year%100 != 0){
			printf("%d is a leap year", year);
		}else {
			if(year%400 == 0){
				printf("%d is a leap year", year);
				return 0; 
			}
			else{
				printf("%d is a century year", year);
				return 0;
			}
		}
}
	else{
		printf("%d is not leap year", year);
		return 0;
	}
	
}
