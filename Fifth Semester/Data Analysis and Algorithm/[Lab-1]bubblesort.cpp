#include <iostream>
using namespace std;
int count = 0;

void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                // Swap A[j] and A[j + 1]
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
            count = count + 8;
        }
        count = count + 5;
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n]; // Create an array of size n

    cout << endl
         << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << endl
         << "Before sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;

    BubbleSort(a, n);

    cout << endl
         << "After sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;
    cout << endl
         << "No. of Steps required: " << count << endl;

    return 0;
}