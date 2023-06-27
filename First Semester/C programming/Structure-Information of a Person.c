#include<stdio.h>

struct person{
	int age;
	char name[10];
};

	void printInfo(struct person *p)
	{
		printf("Name = %s\n", p->name);
				p->age = 100;
		printf("Age = %d\n", p->age);

		
	}

int main()
{

	struct person p0;
		printf("Enter the name: ");
	scanf("%s", &p0.name);
		p0.age = 15;
		printInfo(&p0);
		return 0;
}
