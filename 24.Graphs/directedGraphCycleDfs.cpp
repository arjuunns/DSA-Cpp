#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Function to perform DFS and detect cycles
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& path_vis) {
        vis[node] = 1; // Mark current node as visited
        path_vis[node] = 1; // Mark current node in the current path

        // Traverse all adjacent nodes
        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                // If adjacent node is not visited, recursively call dfs
                bool call = dfs(adjNode, adj, vis, path_vis);
                if (call) return true; // If cycle detected deeper in the recursion, return true
            } else if (path_vis[adjNode] && vis[adjNode]) {
                // If adjacent node is already visited and is in the current path, cycle detected
                return true;
            }
        }

        path_vis[node] = 0; // Backtrack: mark current node as not in current path
        return false; // No cycle found
    }

    // Function to check if any cycle exists in the graph
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0); // Array to mark visited nodes
        vector<int> path_vis(V, 0); // Array to mark nodes in the current recursion stack

        // Perform DFS from each unvisited node
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                bool res = dfs(i, adj, vis, path_vis); // Call DFS for each component
                if (res) return true; // If cycle detected, return true
            }
        }

        return false; // No cycle found in the graph
    }
};
int main() {
    
    return 0;
}