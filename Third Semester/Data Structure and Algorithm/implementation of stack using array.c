#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value){
	if(top == MAX_SIZE-1){
		printf("ERROR! Stack Overflow\n");
	}
	else{
		stack[++top] = value ;
		printf("The element %d is pushed to the stack\n", value);
	}
}
void pop(){
	if(top == -1){
		printf("ERROR! Stack Underflow\n");
	}
	else{
		printf("The popped element is %d\n", stack[top--]);
	}
}
void display() {
    int i;
    if (top == -1) {
        printf("ERROR! Stack is empty\n");
    } else {
        printf("The elements of the stack are: ");
        for (i = top; i >= 0; i--) {
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}

int main(){
	int option,value,i;
	
     printf("Enter the stack operation\n 1. Push\n 2. Pop\n 3. Display Elements\n 4. Exit\n");
     do{
     printf("Your Choice: ");
	 scanf("%d",&option);
	 
	 switch(option){
	 	case 1: printf("Enter the element to be pushed into stack: ");
	 			scanf("%d", &value);
	 			push(value);
	 			break;
	 	
	 	case 2: pop();
	 			break;
	 			
	 	case 3: display();
	 			break;
	 			
		case 4: printf("Exiting Program");
				exit(0);
				
		default: printf("Invalid!!\n");
				 	break;
		
	}
}
	while(1);
}
