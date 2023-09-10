#include <stdio.h>
#include <stdlib.h>

#define MAX 999 // Define MAX globally
int parent[MAX];

int find(int);
int uni(int, int);

void kruskal(int n, int cost[][n])
{
    int i, j, k, a, b, u, v;
    int min;
    int ne = 1;
    int mincost = 0;

    printf("\nThe edges of Minimum Cost Spanning Tree are\n");
    while (ne < n)
    {
        for (i = 1, min = MAX; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = MAX;
    }
    printf("\nMinimum cost = %d\n", mincost);
}

int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    int i, j, n;
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);
    int cost[n][n];
    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = MAX;
        }
    }

    kruskal(n, cost);

    return 0;
}
