#include <algorithm>
#include <iostream>
using namespace std;

struct Item {
  int value, weight;
};

int c;

bool cmp(Item a, Item b) {
  double r1 = (double)a.value / a.weight;
  double r2 = (double)b.value / b.weight;
  c = c + 4;
  return r1 > r2;
}

double fractionalKnapsack(Item arr[], int N, int size) {
  sort(arr, arr + size, cmp);
  double finalvalue = 0.0;
  c += 2;
  for (int i = 0; i < size; i++) {
    if (arr[i].weight <= N) {
      N -= arr[i].weight;
      finalvalue += arr[i].value;
      c += 4;
    } else {
      finalvalue += arr[i].value * ((double)N / arr[i].weight);
      c += 6;
      break;
    }
    c = c + 4;
  }
  return finalvalue;
}

int main() {
  int N = 60;
  Item arr[] = {{100, 10}, {280, 40}, {120, 20}, {120, 24}};
  int size = sizeof(arr) / sizeof(arr[0]);
  cout << "Maximum profit earned = " << fractionalKnapsack(arr, N, size)
       << endl;
  cout << "No. of steps required = " << c << endl;
  return 0;
}