#include <iostream>
using namespace std;

template <typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
template <typename T>
void show(T arr[], int n){
	for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
        cout << std::endl;
}

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    show(arr,n);
    cout << std::endl;

    bubbleSort(arr, n);

    cout << "After sorting: ";
 show(arr,n);

    return 0;
}