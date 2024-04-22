#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int source,destination,weight;
//     Edge(int s,int d,int w):source(s),destination(d),weight(w){}
};

void Bellman_Ford(vector<Edge> &graph,int e,int v,int source){
    //initialise distance array
    vector<int> distance(v+1,INT_MAX);
    vector<int> predecessor(v+1,-1);
    distance[source]=0;

    //algorithm:
    for(int i=0;i<v-1;i++){
        for(auto edge:graph){
            int u=edge.source;
            int v=edge.destination;
            int w=edge.weight;

            //relaxation:
            if(distance[u]!=INT_MAX && distance[v]>(distance[u]+w)){
                distance[v]=distance[u]+w;
                predecessor[v]=u;
            }
        }
    }
    //print shortest distance:
    cout<<"Shoretest distances :\n";
    for(int i=1;i<=v;i++){
        cout<<source<<"-"<<i<<" -> "<<distance[i]<<endl;
    }
    cout<<"Paths :\n";
    for(int i=1;i<=v;i++){
        int u=i;
        cout<<u;
        while(u!=source){
            cout<<" <- "<<predecessor[u];
            u=predecessor[u];
        }
        cout<<endl;
    }
}

int main(){
    int v,e,source;//number of vertices,number of edges,source node
    cin>>v>>e;
    vector<Edge> graph(e);
    for(int i=0;i<e;i++)
        cin>>graph[i].source>>graph[i].destination>>graph[i].weight;
    cin>>source;    
    Bellman_Ford(graph,e,v,source);
    return 0;
}