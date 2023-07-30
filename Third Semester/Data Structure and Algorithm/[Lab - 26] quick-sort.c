#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1, j;

    for (j = low; j <= high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
        swap(&arr[i++], &pivot);
    }
    return i;
}

void quickSort(int *arr, int low, int high)
{
    if (low >= high)
        return;

    int p;
    p = partition(arr, low, high);

    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
}

int main()
{
    int n;
    printf("Enter the total no. of elements: ");
    scanf("%d", &n);
    int *numbers = (int *)malloc(n * sizeof(int)), i;
    printf("Enter %d numbers\n", n);
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
    quickSort(numbers, 0, n - 1);
    printf("The numbers after sorting using quick sort: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", numbers[i]);
    }
    printf("\n");
}
