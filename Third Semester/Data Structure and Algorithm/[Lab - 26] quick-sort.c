#include <stdio.h>

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int x = low;
    int y = high;

    while (x < y)
    {
        while (arr[x] <= pivot && x < high)
        {
            x++;
        }
        while (arr[y] > pivot)
        {
            y--;
        }
        if (x < y)
        {
            int temp = arr[x];
            arr[x] = arr[y];
            arr[y] = temp;
        }
    }

    arr[low] = arr[y];
    arr[y] = pivot;

    return y;
}

void quickSort(int *arr, int low, int high)
{
    int p;
    if (low < high)
    {
        p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter the total no. of elements: ");
    scanf("%d", &n);
    int numbers[n], i;
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
