/* Floyd-Wasrshall Algorithm
    1-adjacency matrix/list for graph
    2- distance matrix(initialised infinite for no direct path) , predecessor matrix(initialised -1 for no direct path)

*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int v,e;
    cout<<"Enter the number of vertices and edges :\n";
    cin>>v>>e;
    vector<vector<int>> graph(e,vector<int>(3));
    cout<<"Enter the graph :\n";
    for(int i=0;i<v;i++)
        cin>>graph[i][0]>>graph[i][1]>>graph[i][2];
    
    return 0;
}