#include<stdio.h>


struct person1
{
  int age;
  char name[10];
  float salary;
} p1;

struct person2
{
  int age;
  char name[10];
  float salary;
} p2;

int main ()
{
	printf ("size of structure = %d", sizeof(p1));
	printf ("size of structure = %d", sizeof(p1));
}