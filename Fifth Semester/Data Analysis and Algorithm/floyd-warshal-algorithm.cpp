#include <iostream>
#define V 6
#define INF 99999
using namespace std;
void printSolution(int dist[][V]);
int count = 0;
void floydWarshall(int dist[][V])
{
    int i, j, k;
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {

            for (j = 0; j < V; j++)
            {

                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    count = count + 6;
                }
                count = count + 4;
            }
            count = count + 4;
        }
        count = count + 4;
    }
    printSolution(dist);
}
void printSolution(int dist[][V])
{
    cout << "The following matrix shows the shortest distances between every pair of vertices \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int graph[V][V] = {{0, 8, INF, 10, 6, 5},
                       {INF, 0, 3, 5, INF, 0},
                       {4, INF, 0, 1, 8, INF},
                       {9, 6, INF, 1, 3, 0}};
    floydWarshall(graph);
    cout << "Required No of steps : " << count << endl;
    return 0;
}
