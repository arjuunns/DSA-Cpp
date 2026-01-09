#include <bits/stdc++.h>
using namespace std;
// Storing a Graph => 
int main() {
    int n=5,m=6; //  m => represent number of edges

    // 1) using adjacency matrix =>
    // vector<vector<int> >adj(n+1,vector<int>(n+1,0));
    // for(int i = 0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u][v]=1;
    //     adj[v][u]=1; // remove this line in case of directed graph
    // }
    // for(auto x : adj){
    //     for(auto y : x){
    //         cout<<y<< " ";
    //     }
    //     cout<<endl;
    // }

    // incase of given wights => store the wights instead of 1 in the matrix

    // 2 => using adjaceny list (array of vector type)
    vector<int> adj[n+1]; // Space complexity => O(2E) where E means number of edges, incase of directed graph S.C. = O(E)
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); // remove this line in case of directed graph
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" "; 
        }
        cout<<endl;
    }
    // incase weights are given => use vector<pair<int,int>> adj[n+1] and store {node,weight} in the adjacency list.
    return 0;
}