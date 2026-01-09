#include <bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int> *adj,vector<bool>&vis,vector<int>&ans){
    if(vis[node]) return ;
    ans.push_back(node);
    vis[node] = true;
    // traverse all its neighbours 
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ans);
        }
    }
    return;
}
int main() {
    int n = 8;
    vector<bool>vis(n+1,false);
    vector<int> adj[n+1] = {{},{2,3},{5,6,1},{4,7,1},{3,8},{2},{2},{3,8},{7,4}};
    vector<int>ans;
    int start = 1;
    dfs(start,adj,vis,ans);
    for(auto it : ans) cout<<it<<" ";
    return 0;
}