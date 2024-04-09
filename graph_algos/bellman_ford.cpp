#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int source, destination, weight;
};

void bellmanFord(int n, int m, vector<Edge>& edges, int startNode) {
    vector<int> distance(n + 1, INT_MAX); // Increase size by 1
    distance[startNode] = 0;

    // Relax all edges for (n-1) iterations
    for (int i = 0; i < n - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    cout<<"Distance of every node from source is :\n";
    // Output distances
    for (int i = 1; i <= n; ++i) { // Adjust loop range
        cout << i << " " << distance[i] << endl; // Adjust index
    }
}

int main() {
    int n, m;
    cout<<"Enter the number of nodes and edges : \n";   
    cin >> n >> m;
    cout<<"Enter the edges as 'A B weight' :\n";
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    int startNode;
    cin >> startNode;

    bellmanFord(n, m, edges, startNode);

    return 0;
}
