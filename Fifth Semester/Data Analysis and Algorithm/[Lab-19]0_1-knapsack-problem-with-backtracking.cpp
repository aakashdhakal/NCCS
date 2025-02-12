#include <iostream>
using namespace std;

int maxProfit = 0;

void knapSackBacktrack(int W, int wt[], int val[], int n, int currentProfit,
                       int index) {
  // Base Case
  if (index == n || W == 0) {
    maxProfit = max(maxProfit, currentProfit);
    return;
  }

  // Exclude the current item
  knapSackBacktrack(W, wt, val, n, currentProfit, index + 1);

  // Include the current item if it fits in the knapsack
  if (wt[index] <= W) {
    knapSackBacktrack(W - wt[index], wt, val, n, currentProfit + val[index],
                      index + 1);
  }
}

// Driver code
int main() {
  int n;

  // Get the number of items
  cout << "Enter the number of items: ";
  cin >> n;

  int weight[n], profit[n];

  // Get the weights of the items
  cout << "Enter the weights of the items: ";
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }

  // Get the profits of the items
  cout << "Enter the profits of the items: ";
  for (int i = 0; i < n; i++) {
    cin >> profit[i];
  }

  int W;
  cout << "Enter the capacity of the knapsack: ";
  cin >> W;

  knapSackBacktrack(W, weight, profit, n, 0, 0);

  cout << "Maximum profit: " << maxProfit << endl;

  return 0;
}