#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    private : 
    vector<int>parent,size,rank;
    public : 
    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i = 0;i<n+1;i++){
            parent[i]=i;
        }
    }
    int findUParent(int node){
        if(parent[node]==node) return node;
        return parent[node] = findUParent(parent[node]);

    }
    void unionByRank(int u,int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]++;
        }
    }
};
int main(){
DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}