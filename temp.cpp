#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>&vis,vector<vector<int>>&adj){
    vis[node]=1;
    cout<<node<<" ";
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj);
        }
    }
}

void topo(int node,stack<int>&st,vector<int>&vis,vector<vector<int>>&adj){
    vis[node]=1;
    cout<<node<<" ";
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj);
        }
    }
    st.push(node);
}

void bfs(int node,vector<int>&vis,vector<vector<int>>&adj){
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(auto it:adj[curr]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
        }
    }
}

void prims(int node,vector<int>&vis,vector<vector<int>>&adj){
    vector<vector<pair<int,int>>>ad{}
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
}

int main(){
    vector<vecto<
    vector<int>vis(6,0);
    dfs(0,vis,adj);

    stack<int>st;
    topo(1,st,vis,adj);
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }

    int count=0;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,vis,adj);
            count++;
        }
    }
}