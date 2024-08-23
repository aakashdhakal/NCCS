#include <iostream>
using namespace std;
int count = 0;

void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j = j - 1;
            count += 7;
        }
        A[j + 1] = key;
        count += 7;
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
         << "Before sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;

    InsertionSort(a, n);

    cout << "\nAfter sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;

    cout << "\nNo. of Steps required for " << n << " datas is " << count << endl;
    return 0;
}