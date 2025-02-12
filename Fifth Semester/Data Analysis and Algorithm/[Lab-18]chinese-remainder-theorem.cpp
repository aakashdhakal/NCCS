#include <iostream>
using namespace std;

// Function to find modular inverse of a with respect to m
int modInverse(int a, int m) {
  a = a % m;
  for (int x = 1; x < m; x++) {
    if ((a * x) % m == 1) {
      return x;
    }
  }
  return -1; // This indicates that there is no modular inverse
}

int main() {
  int size;

  // Get the size of the arrays
  cout << "Enter the size of the array: ";
  cin >> size;

  int a[size], n[size], m[size], mi[size];
  int M = 1, Y = 0;

  // Get the values of a
  cout << "Enter the values of a: ";
  for (int i = 0; i < size; i++) {
    cin >> a[i];
  }

  // Get the values of n
  cout << "Enter the values of n: ";
  for (int i = 0; i < size; i++) {
    cin >> n[i];
  }

  // Calculate M
  for (int i = 0; i < size; i++) {
    M *= n[i];
  }
  cout << "\nM = " << M << endl;

  // Calculate m[i] and mi[i]
  for (int i = 0; i < size; i++) {
    m[i] = M / n[i];
    mi[i] = modInverse(m[i], n[i]);

    if (mi[i] == -1) {
      cout << "\nNo modular inverse for " << m[i] << " with mod " << n[i]
           << endl;
      return 1; // Exit if modular inverse is not found
    }

    cout << "\nm" << i << " = " << m[i];
    cout << "\nm" << i << " inverse = " << mi[i];
  }

  // Calculate final value of Y
  for (int i = 0; i < size; i++) {
    Y += a[i] * m[i] * mi[i];
  }

  // Output result
  Y = Y % M;
  cout << "\n\nChinese Remainder (Y MOD M): " << Y << endl;

  return 0;
}