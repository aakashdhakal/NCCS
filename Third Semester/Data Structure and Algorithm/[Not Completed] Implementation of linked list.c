#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node Node;
Node *start = NULL;
void insert();
void display();

int main()
{

     int option;
   
    do{
    	 printf("\n 1. Insert \n 2. Display\n 3. Exit\n");
    printf("\nEnter your option: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
       insert();
        break;
    case 2:
    	display();
        break;
    case 3:
        break;
    default:
        printf("Invalid option\n");
        break;
    }
}while(option != 3);
    return 0;
}

void insert()
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    Node *temp;
    int pos,i;
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    int option;
    printf("\n 1. Insert at the beginning\n 2. Insert at the end\n 3. Insert at a given position\n");
    printf("Enter your option: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        newnode->next = start;
        start = newnode;
        break;
    case 2:
        temp = start;
        while(temp->next != NULL){
        	temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = NULL;
        break;
    case 3:
        
        printf("Enter the position: ");
        scanf("%d", &pos);
        i = 0;
        while(i=pos-1){
        	temp = temp->next;
        	i++;
		}
		newnode->next = temp->next;
		temp->next = newnode;
		
        break;
    default:
        printf("Invalid option\n");
        break;
    }
}

void display(){
	Node *temp;
	temp = start;
	if(start == NULL){
		printf("The list is empty");
	}
	while(temp!= NULL){
		printf("%d\n", temp->data);
		temp = temp->next;
		
	}
}
