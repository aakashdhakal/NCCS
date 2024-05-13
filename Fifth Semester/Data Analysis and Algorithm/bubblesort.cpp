#include <iostream>
using namespace std;

void bubbleSort(int number[], int n, int& steps)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            steps++; // Incrementing the steps count for comparison
            if (number[j] > number[j + 1])
            {
                steps++; // Incrementing the steps count for swap
                temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
            }
        }
    }
    cout << "The numbers after sorting: ";
    for (i = 0; i < n; i++)
    {
        cout << number[i] << "\t";
    }
}

int main()
{
    int n, steps = 0;
    cout << "Enter the total no. of elements: ";
    cin >> n;
    int numbers[n], i;
    cout << "Enter " << n << " numbers: ";
    for (i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    cout << "The numbers before sorting: ";
    for (i = 0; i < n; i++)
    {
        cout << numbers[i] << "\t";
    }
    cout << endl;
    bubbleSort(numbers, n, steps);
    cout << "\nTotal steps: " << steps << endl;
    return 0;
}
