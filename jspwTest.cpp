/*Edmonds Karp Algorithm
1-modified bfs function to return bottleneck value along various augmenting paths
2-edmonds karp function to implement algorithm and find max flow
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1E9;

int bfs(vector<vector<int>> &graph, vector<int> &parent ,int source,int sink){
    //init data structures
    fill(parent.begin(),parent.end(),-1);
    parent[source]=-2;
    queue<pair<int,int>> q;
    q.push({source,INF});
    cout<<"bfs\n";
    //bfs on graph
    while(!q.empty()){
        int u=q.front().first;
        int flow=q.front().second;
        q.pop();
        for(int v=1;v<=graph.size();v++){
            if(parent[v]==-1 && graph[u][v]!=0){
                parent[v]=u;
                int bflow=min(flow,graph[u][v]);
                if(v==sink)
                    return bflow;
                q.push({v,bflow});
            }
        }
    }
    return 0;
}

void Edmonds_Karp(vector<vector<int>> &graph, int source,int sink){
    //init parent array
    vector<int> parent(graph.size());
    int max_flow=0;
    int new_flow;
    cout<<"ed karp\n";
    //algorithm
    while(new_flow=bfs(graph,parent,source,sink)){
        max_flow+=new_flow; //updating max flow
        int u = sink;
        while(u!=source){
            int v = parent[u];
            graph[v][u]-=new_flow;
            graph[v][u]+=new_flow;
            u=v;
        }
    }
    cout<<"Maximum flow from the network is "<<max_flow<<endl;
}

int main(){
    int v,e,m,n,w,s,t;
    cin>>v>>e;
    vector<vector<int>> graph(v+1,vector<int>(v+1,0));
    for(int i=0;i<e;i++){
        cin>>m>>n>>w;
        graph[m][n]=w;
    }
    cin>>s>>t;
    cout<<"Input taken\n";
    Edmonds_Karp(graph,s,t);
    return 0;
}