/* Floyd-Wasrshall Algorithm
    1-adjacency matrix/list for graph
    2- distance matrix(initialised infinite for no direct path) , predecessor matrix(initialised -1 for no direct path)

*/
#include <bits/stdc++.h>
using namespace std;

void Floyd_Warshall(vector<vector<int>> &graph, int v)
{
    // initialising distance and predecessor matrix :
    vector<vector<int>> distance(v, vector<int>(v, INT_MAX));
    vector<vector<int>> predecessor(v, vector<int>(v, -1));

    for (auto edge : graph)
    {
        int m = edge[0] - 1;
        int n = edge[1] - 1;
        distance[m][n] = edge[2];
        if (m != n && distance[m][n] != INT_MAX)
            predecessor[m][n] = m;
    }

    // calculating shortest paths :
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX)
                {
                    if (distance[i][j] > (distance[i][k] + distance[k][j]))
                    {
                        distance[i][j] = (distance[i][k] + distance[k][j]);
                        predecessor[i][j] = k;
                    }
                }
            }
        }
    }
    // vertex to itself :
    for (int i = 0; i < v; i++)
        distance[i][i] = 0;
    // printing distance matrix :
    cout << "Distance matrix :\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (distance[i][j] == INT_MAX)
                cout << "INF\t";
            else
                cout << distance[i][j] << "\t";
        }
        cout << endl;
    }
    // printing predecessor matrix :
    cout << "Predecessor matrix :\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << predecessor[i][j]+1 << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int v, e;
    cout << "Enter the number of vertices and edges :\n";
    cin >> v >> e;
    vector<vector<int>> graph(e, vector<int>(3));
    cout << "Enter the graph :\n";
    for (int i = 0; i < e; i++)
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
    Floyd_Warshall(graph, v);
    return 0;
}