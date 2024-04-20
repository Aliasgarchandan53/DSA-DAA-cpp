/* Ford Fulkerson algorithm
    1- Requires depth first search 
    2- Ford Fulkerson function initialises  a parent array
    3- in a while loop, dfs function is called which looks for augmenting paths and updates the parent array whenever a path is foun
        it returns true if a path is found and false if not . Hence, the algorithm stops when no more augmenting paths can be found 
    4- the DFS function performs a modified depth first search over the graph and edits the parent array while traversing the augmenting path .
    5- It returns true when the traversal reaches sink from source .
    6- If the stack is empty and no paths are found, it returns false indicating no more augmenting paths are left .
    7- The ford fulkerson method finds the bottleneck flow by backtracking the parent array and calculating minimum flow value.
        It the updates all edges of graph with the value.
*/

#include <bits/stdc++.h>
using namespace std;

bool DFS(vector<vector<int>> &graph , vector<int> &parent,int source , int sink){

    //initialisation
    int n = graph.size();
    vector<int>visited(n,false);
    stack<int> stk;
    visited[0]=true; //0th element of visited array is useless.

    //visiting source node:
    stk.push(source);
    visited[source]=true;
    parent[source]=-1;

    //dfs and finding augmenting paths:
    while(!stk.empty()){
        int u = stk.top();
        stk.pop();
        for(int v=2;v<n;v++){
            if(!visited[v] && graph[u][v]>0){
                parent[v]=u;
                visited[v]=true;
                stk.push(v);
                if(v==sink)
                    return true; //augmenting path is found
            }
        }
    }
    return false; //if no augmenting paths are left.
}

int Ford_Fulkerson(vector<vector<int>> &graph , int source , int sink){

    //initialising parent array
    int n = graph.size();
    vector<int> parent(n);
    int max_flow =0;

    //calculating max_flow :
    while(DFS(graph,parent,source,sink)){
        int bottleneck_val = INT_MAX;
        
        for(int v=sink;v!=source;v=parent[v]){ //finding bottleneck value along augmenting path by backtracking the path
            int u = parent[v];
            bottleneck_val=min(bottleneck_val,graph[u][v]);
        }
        
        for(int v=sink;v!=source;v=parent[v]){ //updating the graph with bottleneck value by backtracking the path.
            int u = parent[v];
            graph[u][v]-=bottleneck_val;
            graph[v][u]+=bottleneck_val;
        }
        max_flow+=bottleneck_val;
    }
    return max_flow;
}

int main(){
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
    int maxFlow = Ford_Fulkerson(graph, s, t);
    cout << "Maximum flow from source to sink is " << maxFlow << endl;
    return 0;
}