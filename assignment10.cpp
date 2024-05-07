#include<bits/stdc++.h>
using namespace std;
#define V 5

void primsAlgorithm(int graph[V][V]){
	int key[V];
	int parent[V];
	bool tf[V];

	for(int i=0;i<V;i++){
		key[i] = INT_MAX;
		tf[i] = false;
	}

	key[0] = 0;
	parent[0] = -1;

	for (int  i = 0; i < V-1; i++)
	{

		int u = -1, min = INT_MAX;
		for (int k = 0; k < V; k++)
		{
			if(tf[k]==false&&key[k]<min){
				min = key[k];
				u = k;
			}
		}

		tf[u] = true;

		for (int j = 0; j < V; j++)
		{
			if(graph[u][j]&&tf[j]==false&&key[j]>graph[u][j]){
				key[j] = graph[u][j];
				parent[j] = u;
			}
		}
		
		
	}

	for (int l = 1; l < V; l++)
	{
		cout<<parent[l]<<"-"<<l<<" "<<graph[l][parent[l]]<<endl;
	}
	
	

}

int main()
{
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
    // Print the solution
    primsAlgorithm(graph);
 
    return 0;
}