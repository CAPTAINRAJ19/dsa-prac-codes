#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Function to perform Depth First Search traversal
void DFS(int node, vector<vector<int>>& adjMatrix, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < adjMatrix[node].size(); ++i) {
        if (adjMatrix[node][i] && !visited[i])
            DFS(i, adjMatrix, visited);
    }
}

// Function to perform Breadth First Search traversal
void BFS(int start, vector<vector<int>>& adjMatrix, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < adjMatrix[node].size(); ++i) {
            if (adjMatrix[node][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

// Function to check if the graph is connected
bool isConnected(vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size();
    vector<bool> visited(n, false);

    // Perform DFS from the first node
    DFS(0, adjMatrix, visited);

    // Check if all nodes are visited
    for (bool v : visited) {
        if (!v)
            return false;
    }
    return true;
}

// Function to find the number of connected components
int countConnectedComponents(vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size();
    vector<bool> visited(n, false);
    int components = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            DFS(i, adjMatrix, visited);
            components++;
        }
    }
    return components;
}

int main() {
    int n, m; // n is the number of nodes, m is the number of edges
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    // Initialize adjacency matrix
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    // Input edges
    cout << "Enter the edges (node1 node2):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Assuming an undirected graph
    }

    cout << "\nAdjacency Matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nDepth First Search Traversal: ";
    vector<bool> visited(n, false);
    DFS(0, adjMatrix, visited);
    cout << endl;

    cout << "\nBreadth First Search Traversal: ";
    fill(visited.begin(), visited.end(), false);
    BFS(0, adjMatrix, visited);
    cout << endl;

    if (isConnected(adjMatrix))
        cout << "\nThe graph is connected." << endl;
    else {
        cout << "\nThe graph is not connected." << endl;
        int components = countConnectedComponents(adjMatrix);
        cout << "Number of connected components: " << components << endl;
    }

    return 0;
}
