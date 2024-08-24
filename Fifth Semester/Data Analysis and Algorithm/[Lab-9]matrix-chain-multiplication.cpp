#include <bits/stdc++.h>
using namespace std;
int c = 0;

int MatrixChainOrder(int p[], int n)
{
    int m[n][n];

    int i, j, k, L, q;

    for (i = 1; i < n; i++)
    {
        m[i][i] = 0;
        c++;
    }

    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            c = c + 4;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                c = c + 7;
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    c++;
                }

                c = c + 5;
            }
            c = c + 6;
        }
        c = c + 4;
    }

    return m[1][n - 1];
}

int main()
{
    int arr[] = {55, 44, 66, 22, 77};
    int size = 5;
    cout << "Minimum no. of multiplication sign used : " << MatrixChainOrder(arr, size) << endl;
    cout << "No. of step Required : " << c;
}