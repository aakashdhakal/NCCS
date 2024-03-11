#include <stdio.h>

int main()
{
    int i, j, block[10], process[10], n1, n2, min, minIndex;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++)
    {
        printf("Enter memory block %d: ", i + 1);
        scanf("%d", &block[i]);
    }
    printf("Enter the number of processes: ");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++)
    {
        printf("Enter the memory required by process %d: ", i + 1);
        scanf("%d", &process[i]);
    }
    printf("Process\tProcess Size\tMemory Block\n");
    for (i = 0; i < n2; i++)
    {
        min = -1;
        for (j = 0; j < n1; j++)
        {
            if (process[i] <= block[j] && (min == -1 || block[j] - process[i] < min))
            {
                min = block[j] - process[i];
                minIndex = j;
            }
        }
        if (min != -1)
        {
            block[minIndex] -= process[i];
            printf("%d\t\t%d\t\t%d\n", i + 1, process[i], minIndex + 1);
        }
        else
        {
            printf("%d\t\t%d\t\tNot allocated\n", i + 1, process[i]);
        }
    }
    return 0;
}
