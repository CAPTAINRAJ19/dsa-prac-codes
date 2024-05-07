#include<bits/stdc++.h>
using namespace std;
#define V 5

void dijikstrasAlgorithm(int graph[V][V]){
    int distance[V];
    bool tf[V];
    for (int i = 0; i < V; i++)
    {
        distance[i] = INT_MAX;
        tf[i] = false;
    }

    distance[0] = 0;
    for (int i = 0; i < V-1; i++)
    {
        int u = 0, min = INT_MAX;
        for (int j = 0; j < V; j++)
        {
            if(tf[j]==false&&distance[j]<min){
                min = distance[j];
                u = j;
            }
        }

        tf[u] = true;

        for (int k = 0; k < V; k++)
        {
            if(graph[u][k]&&tf[k]==false&&distance[k]>distance[u]+graph[u][k]&&distance[u]!=INT_MAX){
                distance[k] = distance[u]+graph[u][k];
            }
        }
        
        
    }
    
    for (int i = 1; i < V; i++)
    {
        cout<<i<<" --> "<<distance[i]<<endl;
    }
    


}