#include <stdio.h>

void shellSort(int *arr, int n)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
            for (j = i; j >= gap; j -= gap)
            {
                if (temp < arr[j - gap])
                {
                    arr[j] = arr[j - gap];
                }
                else
                {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    int n;
    printf("Enter the total no. of elements: ");
    scanf("%d", &n);
    int numbers[n], i;
    printf("Enter %d numbers\n",n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }
    printf("The numbers before sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", numbers[i]);
    }
    printf("\n");
    shellSort(numbers, n);
    printf("The numbers after sorting using shell sort: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", numbers[i]);
    }
    printf("\n");
}
