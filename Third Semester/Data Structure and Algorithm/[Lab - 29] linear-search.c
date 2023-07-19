#include <stdio.h>

void linearSearch(int *arr, int key, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            printf("\nThe key %d is found in index %d\n", key, i);
            return;
        }
    }
    printf("\nThe key %d is not found in the array\n", key);
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
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    linearSearch(numbers, key, n);
}
