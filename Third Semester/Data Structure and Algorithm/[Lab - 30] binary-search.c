#include <stdio.h>

int binarySearch(int *arr, int key, int n)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else if (key > arr[mid])
        {
            low = mid + 1;
        }
    }
    return -1;
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
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    int index = binarySearch(numbers, key, n);
    if (index == -1)
    {
        printf("\nThe key %d is not found in the array\n", key);
    }
    else
    {
        printf("\nThe key %d is found in index %d\n", key, index);
    }
}
