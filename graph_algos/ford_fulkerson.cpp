#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& residualGraph, vector<int>& parent, int source, int sink) {
    int n = residualGraph.size();
    vector<bool> visited(n, false);
    stack<int> stk;
    stk.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                stk.push(v);
                parent[v] = u;
                visited[v] = true;
                if (v == sink)
                    return true;
            }
        }
    }
    return false;
}

int fordFulkerson(vector<vector<int>>& graph, int source, int sink) {
    int n = graph.size();
    vector<vector<int>> residualGraph(graph);

    int maxFlow = 0;
    vector<int> parent(n);

    while (dfs(residualGraph, parent, source, sink)) {
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main() {
    int v, e, m, n, d, s, t;
    cout << "Enter the number of vertices and edges :\n";
    cin >> v >> e;
    vector<vector<int>> graph(v, vector<int>(v, 0));
    cout << "Enter the graph :\n";
    for (int i = 0; i < e; i++) {
        cin >> m >> n >> d;
        graph[m][n] = d;
    }
    cout << "Enter source and sink vertices :\n";
    cin >> s >> t;
    int maxFlow = fordFulkerson(graph, s, t);
    cout << "Maximum flow from source to sink is " << maxFlow << endl;
    return 0;
}
