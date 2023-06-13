#include <stdio.h>
#define MAX_SIZE 5

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
    q.front = MAX_SIZE - 1;
    q.rear = MAX_SIZE - 1;
    int option;
    printf("Enter the queue operation\n 1. Enqueue\n 2. Dequeue\n 3. Display Elements\n 4. Exit\n");
    do
    {

        printf("\nYour Choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            enqueue(&q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
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
    if ((q->rear + 1) % MAX_SIZE == q->front)
    {
        printf("ERROR! Queue Overflow\n");
    }
    else
    {
        printf("Enter the value to be inserted: ");
        scanf("%d", &value);
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->item[q->rear] = value;
        printf("The element %d is inserted to the queue\n", value);
    }
}

void dequeue(queueType *q)
{
    if (q->front == q->rear)
    {
        printf("ERROR! Queue Underflow\n");
    }
    else
    {
        q->front = (q->front + 1) % MAX_SIZE;
        printf("The deleted element is %d\n", q->item[q->front]);
    }
}

void display(queueType *q)
{
    if (q->front == q->rear)
    {
        printf("ERROR! Queue is empty\n");
    }
    else
    {
        printf("The elements of the queue are: ");
        int i = (q->front + 1) % MAX_SIZE;
        while (i != (q->rear + 1) % MAX_SIZE)
        {
            printf("%d\t", q->item[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("\n");
    }
}
