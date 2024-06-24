#include <iostream>
using namespace std;
int count = 0;

void SelectionSort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int least = A[i];
        int loc = i;

        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < least)
            {
                least = A[j];
                loc = j;
            }

            count = count + 6;
        }
        // Swap the elements
        int temp = A[i];
        A[i] = A[loc];
        A[loc] = temp;

        count = count + 8;
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n]; // Create an array of size n

    cout << "Enter " << n << " elements: ";
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

    SelectionSort(a, n);

    cout << endl
         << "After sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl
         << endl;
    cout << "No. of Steps required for " << n << " datas is " << count << endl;

    return 0;
}