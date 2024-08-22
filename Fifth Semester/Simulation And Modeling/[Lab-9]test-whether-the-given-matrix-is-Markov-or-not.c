#include <stdio.h>
#define N 3
#define M 3

int isMarkovMatrix(float m[][N])
{
    int i, j;
    float s;

    printf("Enter elements of %d*%d matrix:\n", M, N);
    for (i = 0; i < M; i++)
    {
        s = 0;
        for (j = 0; j < N; j++)
        {
            scanf("%f", &m[i][j]);
            s += m[i][j];
        }
        if (s > 1)
            return 0;
    }
    return 1;
}

int main()
{
    float matrix[M][N];
    printf("The matrix is %s Markov matrix.\n", isMarkovMatrix(matrix) ? "a" : "not a");
    return 0;
}