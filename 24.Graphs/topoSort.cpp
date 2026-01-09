#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&ans){
	    vis[node] = 1;
	    for(auto adjNode : adj[node]){
	        if(!vis[adjNode]) dfs(adjNode,adj,vis,ans);
	    }
	    ans.push_back(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int>vis(V,0);
	    vector<int>ans;
	    for(int i = 0;i<V;i++){
	        if(!vis[i]) dfs(i,adj,vis,ans);
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};
int main() {
    
    return 0;
}