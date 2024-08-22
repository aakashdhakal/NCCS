#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int head = 0, tail = 0, itr;
    double r;
    srand(time(NULL));
    printf("Enter number of iterations: ");
    scanf("%d", &itr);
    for (int i = 1; i <= itr; i++)
    {
        r = (double)rand() / RAND_MAX;
        if (r <= 0.5)
            head++;
        else
            tail++;
    }
    printf("Head=  %d\n", head);
    printf("Tail = %d\n", tail);
    if (head > tail)
        printf("Head wins by %d\n", head - tail);
    else
        printf("Tail wins by %d\n", tail - head);
}
