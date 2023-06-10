#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 5

struct queue
{
    int data[MAX];
    int front;
    int rear;
};
typedef struct queue queue;

void enqueue(queue *);
void dequeue(queue *);
void display(queue);

int main()
{
    struct queue Pqueue;
    Pqueue.front = 0;
    Pqueue.rear = -1;

    int option;
    do
    {
        system("cls");
        printf("Enter the queue operation\n 1. Enqueue\n 2. Dequeue\n 3. Display Elements\n 4. Exit\n");
        printf("Your Choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            enqueue(&Pqueue);
            getch();
            break;
        case 2:
            dequeue(&Pqueue);
            getch();
            break;
        case 3:
            display(Pqueue);
            getch();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (option != 4);
    return 0;
}

void enqueue(queue *Pqueue)
{
    int element;
    if (Pqueue->rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter the value to be inserted: ");
        scanf("%d", &element);
        Pqueue->data[++Pqueue->rear] = element;
        printf("Element %d inserted successfully\n", element);
    }
}

void dequeue(queue *Pqueue)
{
    int i, priority = Pqueue->data[Pqueue->front], position = Pqueue->front;
    if (Pqueue->front == Pqueue->rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        for (i = Pqueue->front; i <= Pqueue->rear; i++)
        {
            if (Pqueue->data[i] < priority)
            {
                priority = Pqueue->data[i];
                position = i;
            }
        }
        for (i = position; i < Pqueue->rear; i++)
        {
            Pqueue->data[i] = Pqueue->data[i + 1];
        }
        Pqueue->rear--;
        printf("Element %d deleted successfully\n", priority);
    }
}

void display(queue Pqueue)
{
    int i;
    if (Pqueue.front == Pqueue.rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("The elements in the queue are: ");
        for (i = Pqueue.front; i <= Pqueue.rear; i++)
        {
            printf("%d ", Pqueue.data[i]);
        }
        printf("\n");
    }
}