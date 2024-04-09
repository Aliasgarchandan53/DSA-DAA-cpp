#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void floydWarshall(int n, vector<vector<int>>& graph) {
    // Initialize distance matrix with maximum possible distance
    vector<vector<int>> distance(n, vector<int>(n, INT_MAX));

    // Fill distance matrix with given edges
    for (const auto& edge : graph)
        distance[edge[0] - 1][edge[1] - 1] = edge[2];

    // Set distance for direct edges and initialize diagonal to 0
    for (int i = 0; i < n; ++i) {
        distance[i][i] = 0;
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX &&
                    distance[i][j] > distance[i][k] + distance[k][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    // Print the distance matrix
    cout<<"The distance matrix is as follows :\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (distance[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << distance[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cout<<"Enter the number of nodes and edges : \n";   
    cin >> n >> m;
    cout<<"Enter the edges as 'A B weight' :\n";
    vector<vector<int>> graph(m, vector<int>(3));
    for (int i = 0; i < m; ++i) {
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
    }

    floydWarshall(n, graph);

    return 0;
}
