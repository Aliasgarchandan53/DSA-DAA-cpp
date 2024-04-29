/*Floyd Warshall Algorithm*/

#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
};

void Floyd_Warshall(vector<Edge> &graph, int v, int e)
{

    // initialising distance matrix
    vector<vector<int>> distance(v, vector<int>(v, INT_MAX));
    vector<vector<int>> predecessor(v, vector<int>(v, INT_MIN));

    for (auto edge : graph)
    {
        distance[edge.u - 1][edge.v - 1] = edge.w;
        predecessor[edge.u-1][edge.v-1]=(edge.u-1);
    }
    for (int i = 0; i < v; i++){
        distance[i][i] = 0;
        predecessor[i][i]=-1;
    }

    // floyd_warshall algorithm
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (distance[i][k] != INT_MAX &&
                    distance[k][j] != INT_MAX &&
                    distance[i][j] > (distance[i][k] + distance[k][j]))
                {
                    distance[i][j] = (distance[i][k] + distance[k][j]);
                    predecessor[i][j]=k;
                }
            }
        }
    }

    //final distance matrix 
    cout<<"Distance matrix:\n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(distance[i][j]==INT_MAX)
                cout<<"INF\t";
            else    
                cout<<distance[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Predecessor matrix :\n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(predecessor[i][j]==INT_MIN)
                cout<<"NIL\t";
            else if(predecessor[i][j]==-1)
                cout<<"0\t";
            else    
                cout<<(predecessor[i][j]+1)<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<Edge> graph(e);
    for (int i = 0; i < e; i++)
        cin >> graph[i].u >> graph[i].v >> graph[i].w;
    Floyd_Warshall(graph, v, e);
    return 0;
}