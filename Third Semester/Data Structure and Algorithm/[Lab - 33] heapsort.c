#include <stdio.h>

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void heapify(int *arr, int n, int i)
{
    int largest = i, lc, rc, temp;
    lc = 2 * i + 1;
    rc = lc + 1;

    if (lc < n && arr[lc] > arr[largest])
    {
        largest = lc;
    }
    if (rc < n && arr[rc] > arr[largest])
    {
        largest = rc;
    }
    if (i != largest)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n)
{

    int i;
    for (i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    printf("Enter the total no. of elements: ");
    scanf("%d", &n);
    int arr[n], i;
    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nThe numbers before sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    heapSort(arr, n);
    printf("\n");
    printf("The numbers after sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
