#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& graph, vector<int>& parent, int source, int sink) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> stk;
    stk.push(source);
    visited[source] = true;
    parent[source] = -1;
    visited[0]=true;

    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();
        for (int v = 2; v < n; ++v) {
            if (!visited[v] && graph[u][v] > 0) {
                stk.push(v);
                parent[v] = u;
                visited[v] = true;
                if (v == sink)
                    return true;
            }
            cout<<"visited array\n";
            for(auto it :visited)
                cout<<it<<" ";
            cout<<endl;
            
        }
    }
    return false;
}

int fordFulkerson(vector<vector<int>>& graph, int source, int sink) {
    int n = graph.size();
    // vector<vector<int>> residualGraph(graph);

    int maxFlow = 0;
    vector<int> parent(n);

    while (dfs(graph, parent, source, sink)) {
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, graph[u][v]);
        }
        cout<<"path flow min = "<<pathFlow<<endl;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            graph[u][v] -= pathFlow;
            graph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
        cout<<"Max flow = "<<maxFlow<<endl;
    }
    return maxFlow;
}

int main() {
    int v, e, m, n, d, s, t;
    cout << "Enter the number of vertices and edges :\n";
    cin >> v >> e;
    vector<vector<int>> graph(v+1, vector<int>(v+1, 0));
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
