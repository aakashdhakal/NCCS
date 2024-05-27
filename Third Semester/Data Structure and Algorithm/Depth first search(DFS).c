#include <stdio.h>
#include <stdlib.h>

#define MAX 999

struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1; // Return a sentinel value
    }
    return stack->array[stack->top--];
}

void DFS(int numVertices, int a[][numVertices], int startVertex)
{
    int visited[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = 0;
    }

    struct Stack *stack = createStack(numVertices);
    push(stack, startVertex);

    printf("DFS Traversal  ");

    while (!isEmpty(stack))
    {
        int vertex = pop(stack);
        if (!visited[vertex])
        {
            printf("-> %d", vertex);
            visited[vertex] = 1;
        }

        for (int i = numVertices - 1; i >= 0; i--)
        {
            if (a[vertex][i] == 1 && !visited[i])
            {
                push(stack, i);
            }
        }
    }

    printf("\n");
    free(stack->array);
    free(stack);
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

    DFS(numVertices, a, startVertex);

    return 0;
}
