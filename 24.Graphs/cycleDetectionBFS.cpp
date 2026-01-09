#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        for (int i = 0; i < V; i++) { // incase of disconnected graphs, there might be a cycle in any of the sub graph
        if (!vis[i]) {
            queue<pair<int, int>> q;
            q.push({i, -1}); // Start BFS from node i
            vis[i] = 1;

            while (!q.empty()) {
                int curr = q.front().first;
                int parent = q.front().second;
                q.pop();

                for (auto adjacencyNode : adj[curr]) {
                    if (vis[adjacencyNode] && adjacencyNode != parent) { // agar pehle se hi visited h par parent nahi hai then cycle hai graph mein
                        return true; 
                    }
                    if (!vis[adjacencyNode]) {
                        q.push({adjacencyNode, curr});
                        vis[adjacencyNode] = 1;
                    }
                }
            }
        }
    }
        return false;
    }
};
