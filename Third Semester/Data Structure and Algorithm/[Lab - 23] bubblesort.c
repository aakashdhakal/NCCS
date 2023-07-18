#include <stdio.h>

void bubbleSort(int number[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (number[j] > number[j + 1])
            {
                temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
            }
        }
    }
    printf("The numbers after sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", number[i]);
    }
}

int main()
{
    int n;
    printf("Enter the total no. of elements: ");
    scanf("%d", &n);
    int numbers[n], i;
    printf("Enter %d numbers\n ", n);
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
    bubbleSort(numbers, n);
    printf("\n");
}
