#include<stdio.h>
#include<stdlib.h>

struct stack{
	int data;
	struct stack *next;
};
typedef struct stack node;

void push(node*);
void pop(node*);
void display(node*);

int main(){	
	int option;
	node *top = NULL;
	
	printf("Menu: \n1.Push \n2.Pop \n3.Display \n4.Exit \n\n");
	do{
		printf("\nEnter an option: ");
		scanf("%d",&option);
		
		switch (option){
			case 1:
				push(top);
				break;
			
			case 2:
				pop(top);
				break;
			
			case 3:
				display(top);
				break;
				
			case 4:
				printf("Exiting...");
				break;
				
			default:
				printf("Invalid input\n");
				break;
		}

	}while(option != 4);

	return 0;
}

void push(node *stop){
	if(stop != NULL){
		printf("Not enough memory\n");
		return;
	}
	int value;
	printf("Enter the value to be pushed: ");
	scanf("%d",&value);
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = value;
	newnode->next = stop;
	stop = newnode;
}

void pop(node *stop){
	if(stop == NULL){
		printf("Stack Underflow");
		return;
	}
	printf("The popped value is %d",stop->data);
	
	node* temp;
	temp = stop;
	stop = stop->next;
	free(temp);
}

void display(node *stop){
	if(stop == NULL){
		printf("Stack Underflow");
		return;
	}
	
	node *temp;
	temp = stop;
	printf("The data of the stack are: ");
	while(temp != NULL){
		printf("%d\t",temp->next);
		temp = temp->next;
		
	}
}
