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
    int arr1[] = { 64, 34, 25, 12, 22, 11, 90 };
    float arr2[] = {4.4, 1.2, 0.1, 5.12, 2.4, 9.3, 6.1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Before sorting: ";
    show(arr1,n1);
    cout << endl;
    show(arr2,n2);
    cout << endl;

    bubbleSort(arr1, n1);
    bubbleSort(arr2, n2);

    cout << "After sorting: ";
 	show(arr1,n1);
 	cout << endl;
 	show(arr2,n2);
 	cout << endl;
 	
 	

    return 0;
}