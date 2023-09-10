#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        a = q->arr[++q->f];
    }
    return a;
}

void BFS(int numVertices, int a[][numVertices], int startVertex)
{
    struct queue q;
    q.size = numVertices + 1;
    q.f = q.r = -1;                              // Initialize f and r properly
    q.arr = (int *)malloc(q.size * sizeof(int)); // Dynamically allocate memory

    printf("BFS : %d", startVertex);
    enqueue(&q, startVertex);
    int visited[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = 0;
    }
    visited[startVertex] = 1;

    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < numVertices; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf(" -> %d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    free(q.arr); // Free the dynamically allocated memory
}

int main()
{
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int a[numVertices][numVertices];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    // Call the BFS function
    BFS(numVertices, a, startVertex);
    printf("\n");
    return 0;
}
