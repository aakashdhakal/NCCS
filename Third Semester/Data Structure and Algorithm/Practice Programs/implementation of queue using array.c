#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX_SIZE 10

struct queue
{
    int item[MAX_SIZE];
    int front;
    int rear;
};

typedef struct queue queueType;
void enqueue(queueType *);
void dequeue(queueType *);
void display(queueType *);

int main()
{
    queueType q;
    q.front = 0;
    q.rear = -1;
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
            enqueue(&q);
            getch();
            break;
        case 2:
            dequeue(&q);
            getch();
            break;
        case 3:
            display(&q);
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
void enqueue(queueType *q)
{
    int value;
    if (q->rear == MAX_SIZE - 1)
    {
        printf("ERROR! Queue Overflow\n");
    }
    else
    {
        printf("Enter the value to be inserted: ");
        scanf("%d", &value);
        q->item[++q->rear] = value;
        printf("The element %d is inserted to the queue\n", value);
    }
}
void dequeue(queueType *q)
{
    if (q->front > q->rear)
    {
        printf("ERROR! Queue Underflow\n");
    }
    else
    {
        printf("The deleted element is %d\n", q->item[q->front++]);
    }
}
void display(queueType *q)
{
    int i;
    if (q->front > q->rear)
    {
        printf("ERROR! Queue is empty\n");
    }
    else
    {
        printf("The elements of the queue are: ");
        for (i = q->front; i <= q->rear; i++)
        {
            printf("%d\t", q->item[i]);
        }
        printf("\n");
    }
}
