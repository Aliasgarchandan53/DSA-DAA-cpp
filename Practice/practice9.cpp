/*Edmonds Karp Algorithm
    1- graph in terms of adjacency matrix 
    2-modified breadth first search for finding augmenting paths
    3- queue with pairs ie vertex and associated flow ahead
*/

#include <bits/stdc++.h>
using namespace std;

int modified_BFS(vector<vector<int>> &graph , vector<int> &parent,int source, int sink){

    int n=graph.size();
    fill(parent.begin(),parent.end(),-1);
    queue<pair<int,int>> q;
    q.push({source,INT_MAX});
    parent[source]=-2;

   while(!q.empty()){
    int u = q.front().first;
    int flow = q.front().second;
    q.pop();
    for(int v=1;v<=n;v++){
        if(parent[v]==-1 && graph[u][v]>0){
            parent[v]=u;
            int min_flow = min(flow,graph[u][v]);
            if(v==sink)
                return min_flow;
            q.push({v,min_flow});
        }
    }
   }
    return 0;
}

void Edmonds_Karp(vector<vector<int>> &graph ,int source, int sink){
    //initialising parent array
    vector<int> parent(graph.size());
    int max_flow=0,new_flow;

    while(new_flow = modified_BFS(graph,parent,source,sink)){
        int u = sink;
        max_flow+=new_flow;
        while(u!=source){
            int v = parent[u];
            graph[v][u]-=new_flow;
            graph[u][v]+=new_flow;//residual
            u=v;
        }
    }
    cout<<"Maximum flow from source to sink is "<<max_flow<<endl;
}

int main(){
    int v, e,m,n,d,s,t;
    cout << "Enter the number of vertices and edges :\n";
    cin >> v >> e;
    vector<vector<int>> graph(v+1, vector<int>(v+1,0));
    cout << "Enter the graph :\n";
    for (int i = 0; i < e; i++){
        cin >>m>>n>>d;
        graph[m][n]=d;    
    }
    cout<<"Enter source and sink vertices :\n";
    cin>>s>>t;
    Edmonds_Karp(graph,s,t);
    return 0;
}