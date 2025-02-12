#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define vr 4

// Function to implement Traveling Salesman Problem (TSP)
int TSP(int grph[][vr], int p) {
  vector<int> ver;
  for (int i = 0; i < vr; i++)
    if (i != p)
      ver.push_back(i);

  int m_p = INT_MAX; // Store minimum weight of a graph

  cout << "Steps of the TSP:" << endl << endl;

  do {
    int cur_pth = 0;
    int k = p;

    cout << "Current permutation: " << p << " -> ";
    for (int i = 0; i < ver.size(); i++) {
      cout << ver[i] << " -> ";
      cur_pth += grph[k][ver[i]];
      k = ver[i];
    }
    cur_pth += grph[k][p];
    cout << p << " | Path cost: " << cur_pth << endl;

    m_p = min(m_p, cur_pth); // Update the value of minimum weight
  } while (next_permutation(ver.begin(), ver.end()));

  return m_p;
}

int main() {
  int grph[][vr] = {{0, 2, 9, 10}, // Updated values of the graph
                    {1, 0, 6, 4},
                    {15, 7, 0, 8},
                    {6, 3, 12, 0}};

  int p = 0;
  cout << "\nThe result is: " << TSP(grph, p) << endl;
  return 0;
}
