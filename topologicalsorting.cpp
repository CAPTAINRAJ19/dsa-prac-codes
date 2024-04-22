// Write a C++ program to print topological order of given Directed acyclic Graph in easiest way without external functions.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the number of nodes and edges in the graph:" << endl;
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    vector<int> indegree(n, 0);
    for (int i = 0; i < m; i++)
    {
        cout << "Enter the nodes of edge " << i + 1 << ":" << endl;
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return 0;
}
// here n is the number of nodes and m is the number of edges in the graph.