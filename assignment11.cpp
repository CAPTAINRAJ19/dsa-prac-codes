#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
    vector<int>parent;
    vector<int>rank;

    DSU(int n){
        for (int i = 0; i < n; i++)
        {
            parent.push_back(-1);
            rank.push_back(1);
        }
        
    }

    int find(int x){
        if(parent[x]==-1){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y){
        int s1 = find(x);
        int s2 = find(y);

        if(s1>s2){
            parent[s2] = s1;
        }
        else if(s1<s2){
            parent[s1] = s2;
        }
        else{
            parent[s1] = s2;
            rank[s2]++;
        }
    }

};

class Graph{
    public:
    vector<vector<int>>edges;
    int n;

    Graph(int n){
        this->n = n;
    }
    

    void addEdges(int x, int y,int z){
        
        edges.push_back({z,x,y});
    }

    void kruskalAlgorithm(){
        DSU s(n);
        sort(edges.begin(),edges.end());
        int ans = 0;

        for(auto edge : edges){
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if(s.find(x)!=s.find(y)){
                s.unite(x,y);
                ans+=w;
                cout<<x<<" -- "<<y<<" ---> "<<w<<endl;
            }
        }



    }
};

int main() 
{ 
    Graph g(4); 
    g.addEdges(0, 1, 10); 
    g.addEdges(1, 3, 15); 
    g.addEdges(2, 3, 4); 
    g.addEdges(2, 0, 6); 
    g.addEdges(0, 3, 5); 
  
    // Function call 
    g.kruskalAlgorithm(); 
  
    return 0; 
}