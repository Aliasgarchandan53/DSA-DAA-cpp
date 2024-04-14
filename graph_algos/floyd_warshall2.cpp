#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(vector<vector<int>> &graph,int v ){
    cout<<"Floyd warshall called \n";

    //Initialising the distance matrix
    vector<vector<int>> distance(v,vector<int>(v,INT_MAX));
    vector<vector<int>> predecessor(v,vector<int>(v,-1));

    //initialising distance matrix
    for(auto edge:graph){
        int m = edge[0]-1;
        int n = edge[1]-1;
        distance[m][n]=edge[2];
        if(m!=n && distance[m][n]!=INT_MAX)
            predecessor[m][n]=m;
    }

    for(int i=0;i<v;i++)
        distance[i][i]=0;

    //applying the algorithm :
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(distance[i][k]!=INT_MAX && distance[k][j]!=INT_MAX){
                    if(distance[i][j] > (distance[i][k]+distance[k][j])){
                        distance[i][j] = (distance[i][k]+distance[k][j]);
                        predecessor[i][j]=k;
                    }
                }
            }
        }
    }

    //printing distance matrix :
    cout<<"The distance matrix for the graph :\n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(i==0 && j==0){
                cout<<"\t";
                for(int k=0;k<v;k++){
                    cout<<(k+1)<<"\t";
                }
                cout<<endl;
            }
            if(j==0){
                cout<<(i+1)<<"|\t";
            }
            if(distance[i][j]==INT_MAX)
                cout<<"INF\t";
            else
                cout<<distance[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout << "\nPredecessor Matrix:\n";
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            cout << predecessor[i][j] + 1 << "\t"; // Add 1 to convert back to 1-based indexing
        }
        cout << endl;
    }
}

int main(){
    int v,e;
    cout<<"Enter number of vertices and edges :\n";
    cin>>v>>e;
    vector<vector<int>> graph(e,vector<int>(3));
    cout<<"Enter the edges in the form if 3 integers (u,v,w) :\n";
    for(int i=0;i<e;i++)
        cin>>graph[i][0]>>graph[i][1]>>graph[i][2];
    floyd_warshall(graph,v);
    return 0;
}
