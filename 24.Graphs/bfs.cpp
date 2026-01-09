#include <bits/stdc++.h>
using namespace std;
vector<int> bfsOfGraph(int N, vector<int> adj[]){
    queue<int> q;
    vector<int> ans;
    q.push(0);
    vector<bool> vis(N, false);
    while (!q.empty()){
        int ele = q.front();
        ans.push_back(ele);
        q.pop();
        for (auto it : adj[ele]){
            if (!vis[it]){
                vis[it] = true;
                q.push(it);
            }
        }
    }
    return ans;
}
int main(){

    return 0;
}