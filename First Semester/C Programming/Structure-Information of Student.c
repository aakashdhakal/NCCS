#include<stdio.h>

struct DOB
{
  int year;
  int month;
  int day;
};

struct student
{
  int roll;
  char name[10];
  char address[50];
  struct DOB dob;

};

int main ()
{
  struct student s0;
	printf ("Enter your roll no: ");
	scanf ("%d", &s0.roll);
	printf ("Enter your name: ");
	scanf ("%[^\n]s", &s0.name);
	printf ("Enter your address: ");
	scanf ("%[^\n]s", &s0.address);
	printf ("Enter your Date Of Birth(yy/mm/dd): ");
	scanf ("%d/%d/%d", &s0.dob.year, &s0.dob.month, &s0.dob.day);
	
	
	printf("\nInformation of Student\n______________________\n");
	printf("Roll no: %d\n",s0.roll);
	printf("Name: %s\n",s0.name);
	printf("Address: %s\n",s0.address);
	printf("Date of Birth: %d/%d/%d\n",s0.dob.year, s0.dob.month, s0.dob.day);
  return 0;
}
