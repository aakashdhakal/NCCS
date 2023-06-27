#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;
Node *top = NULL;

void push();
void pop();
void display();

int main()
{
    int option;
    printf("\n 1. Push\n 2. Pop\n 3. Display\n 4. Exit\n");

    do
    {
        printf("\nEnter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    } while (option != 4);
    return 0;
}

void push()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = top;
    top = newNode;
    printf("%d is pushed into stack\n", newNode->data);
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    Node *temp = top;
    top = top->next;
    printf("%d is popped from stack\n", temp->data);
    free(temp);
}

void display()
{
    if (top == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    Node *temp = top;
    printf("Stack: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
