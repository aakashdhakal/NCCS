#include<stdio.h>

int main()
{
	FILE *fw;
		int id;
		char name[10];
		char address[20];
			printf("Please enter the following details of the file\n----------------------------------------------\n");
			printf("ID: ");
			scanf("%d", &id);
			printf("Name: ");
			scanf("%[^\n]%*c", &name);
			printf("Address: ");
			scanf("%[^\n]%*c", &address);
			
		fw = fopen("abc.txt","w");
		fprintf(fw,"%d\t%s\t%s/n",id,name,address);
		fclose(fw);
		return 0;
}