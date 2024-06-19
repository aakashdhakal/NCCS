#include <iostream>
using namespace std;
int step = 0; 
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    step=step+7;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
      step=step+4;; 
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
        step=step+4;; 
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
        step=step+2;
    }
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
        step=step+6;
	}    
for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        step=step+6;
    }  
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int a[n];
    cout << "Enter the Elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Elements before sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
    heapSort(a, n);
    cout << "Elements after sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
    cout << "Total number of steps: " << step
	 << endl;
    return 0;
}
