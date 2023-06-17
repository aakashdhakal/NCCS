#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, n, i, max;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", ptr + i);
    }

    max = *ptr;
    for (i = 0; i < n; i++)
    {
        if (*(ptr + i) > max)
        {
            max = *(ptr + i);
        }
    }
    printf("The largest number is %d\n", max);
    return 0;
}
