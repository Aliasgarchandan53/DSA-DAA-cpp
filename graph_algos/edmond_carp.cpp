#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1e9;

// Represents an edge in the graph
struct Edge {
    int u, v, capacity, flow;
};

// Function to perform BFS to find augmenting paths
int bfs(vector<vector<int>>& graph, vector<int>& parent, int source, int sink) {
    int n = graph.size();
    fill(parent.begin(), parent.end(), -1);
    parent[source] = -2;
    queue<pair<int, int>> q;
    q.push({source, INF});

    while (!q.empty()) {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int v = 1; v <= n; ++v) { // Adjusted loop range
            if (parent[v] == -1 && graph[u][v] > 0) {
                parent[v] = u;
                int new_flow = min(flow, graph[u][v]);
                if (v == sink)
                    return new_flow;
                q.push({v, new_flow});
            }
        }
    }
    return 0;
}

// Implementation of Edmonds-Karp algorithm
int edmondsKarp(vector<vector<int>>& graph, int source, int sink) {
    int maxFlow = 0;
    vector<int> parent(graph.size());

    // Augment the flow until no more augmenting paths are found
    int new_flow;
    while (new_flow = bfs(graph, parent, source, sink)) {
        maxFlow += new_flow;
        int u = sink;
        while (u != source) {
            int v = parent[u];
            graph[v][u] -= new_flow;
            graph[u][v] += new_flow;
            u = v;
        }
    }

    return maxFlow;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and the number of edges: ";
    cin >> n >> m;

    // Initialize adjacency matrix with 0 capacities
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0)); // Adjusted size and indexing

    cout << "Enter the edges in the format (u v w), where u->v has capacity w:\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    int source, sink;
    cout << "Enter the source and sink node indices: ";
    cin >> source >> sink;

    int maxFlow = edmondsKarp(graph, source, sink);
    cout << "The maximum flow from source to sink is: " << maxFlow << endl;

    return 0;
}
