#include <iostream>

using namespace std;

int c[100][100];

void Knapsack(int W, int n, int wt[], int v[]) {
    for (int i = 0; i <= n; i++)
        c[i][0] = 0;

    for (int w = 0; w <= W; w++)
        c[0][w] = 0;

    for (int i = 0; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] > w)
                c[i][w] = c[i - 1][w];
            else {
                if ((v[i - 1] + c[i - 1][w - wt[i - 1]]) > c[i - 1][w]) {
                    c[i][w] = v[i - 1] + c[i - 1][w - wt[i - 1]];
                } else {
                    c[i][w] = c[i - 1][w];
                }
            }
        }
    }
}

int main() {
    int w[100];
    int v[100];
    int W, n;

    cout << "Enter the capacity and number of items: ";
    cin >> W >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter weight and value of [" << i + 1 << "] item: ";
        cin >> w[i] >> v[i];
    }

    Knapsack(W, n, w, v);

    for (int i = 0; i < n; i++) {
        for (int wt = 0; wt <= W; wt++) {
            cout << c[i][wt] << "\t";
        }
        cout << endl;
    }

    return 0;
}
