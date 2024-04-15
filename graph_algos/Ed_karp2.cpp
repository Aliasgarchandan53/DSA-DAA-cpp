#include <bits/stdc++.h>
using namespace std;

const int INF =1e9;

int modified_BFS(vector<vector<int>> &graph, vector<int> &parent, int source, int sink){

    //initialization :
    int n= graph.size();
    fill(parent.begin(),parent.end(),-1);
    parent[source]=-2;
    queue<pair<int,int>> q;
    q.push({source,INF});

    //breadth-first-search:
    while(!q.empty()){
        int u = q.front().first;
        int flow=q.front().second;
        q.pop();
        for(int v=1;v<=n;v++){
            if(parent[v]==-1 && graph[u][v]>0){
                parent[v]=u;
                int min_bflow = min(flow,graph[u][v]);
                if(v==sink) 
                    return min_bflow;
                q.push({v,min_bflow});
            }
        }
    }
    return 0;
}
int Edmonds_Karp(vector<vector<int>> &graph, int source, int sink){

    //initialising essentials ;
    vector<int> parent(graph.size());
    int max_flow=0;
    int new_flow;
    while(new_flow = modified_BFS(graph,parent,source,sink)){
        int u = sink;
        max_flow+=new_flow;
        while(u!=source){
            int v = parent[u];
            graph[v][u]-=new_flow;
            graph[u][v]+=new_flow;
            u=v;
        }
    }
    return max_flow;
}

int main(){
    int v,e,s,d,w,source,sink;
    cout<<"Enter the number of vertices and edges :\n";
    cin>>v>>e;

    vector<vector<int>> graph(v+1,vector<int>(v+1,0));
    cout<<"Enter the edges as source , destination,weight :\n";
    for(int i=0;i<e;i++){
        cin>>s>>d>>w;
        graph[s][d]=w;
    }

    cout<<"Enter the source and sink nodes :\n";
    cin>>source>>sink;

    int result=Edmonds_Karp(graph,source,sink);
    cout<<"The maximum flow from source to sink is : "<<result<<endl;

    return 0;
}