#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;
Node *front = NULL;
Node *rear = NULL;

void enqueue();
void dequeue();
void display();

int main()
{
    int option;
    printf("\n 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit\n");

    do
    {
        printf("\nEnter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
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

void enqueue()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = newNode;
    }
    else
    {
        rear->next = newNode;
    }
    rear = newNode;
    printf("%d is enqueued into queue\n", newNode->data);
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue underflow\n");
    }
    else
    {
        Node *temp = front;
        front = front->next;
        free(temp);
        printf("%d is dequeued from queue\n", temp->data);
    }
}

void display()
{
    if (front == NULL)
    {
        printf("Queue underflow\n");
    }
    else
    {
        Node *temp = front;
        printf("The queue is: ");
        while (temp != NULL)
        {
            printf("%d\t ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}