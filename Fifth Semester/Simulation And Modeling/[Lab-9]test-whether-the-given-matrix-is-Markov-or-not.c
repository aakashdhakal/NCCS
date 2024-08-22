#include <stdio.h>
#define N 3
#define M 3
int isMarkovMatrix(float m[][N])
{
    int i, j, s, t = 1;
    for (i = 0; i < M; i++)
    {
        s = 0;
        for (j = 0; j < N; j++)
        {
            s = s + m[i][j];
        }
        if (s > 1)
        {
            t = 0;
            break;
        }
    }
    return t;
}
void read(float m[][N])
{
    printf("Enter element of %d*%d matrix\n", M, N);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%f", &m[i][j]);
        }
    }
}
int main()
{
    float matrix[M][N];
    read(matrix);
    if (isMarkovMatrix(matrix))
        printf("The matrix is Markov Matrix\n");
    else
        printf("The matrix is not Markov matrix\n");
    return 0;
}
