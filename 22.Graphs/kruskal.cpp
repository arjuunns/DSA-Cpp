// dsu + greedy
// tc : O(edges)
// sc : O(edges)
class DisjointSet{
    private : vector<int>parent,size;
    public : 
    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,0);
        for(int i = 0;i<n+1;i++){
            parent[i]=i;
        }
    }
    int findUParent(int node){
        if(parent[node]==node) return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]++;
            
    }
    }
};

class Solution {
  public:
    static bool comparator(vector<int>&a,vector<int>&b){
        return a[2] < b[2];
    }
    int spanningTree(int V, vector<vector<int>>& edges) { // [u,v,w]
        int sum = 0;
        sort(edges.begin(),edges.end(),comparator);
        DisjointSet ds(V);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(ds.findUParent(u)!=ds.findUParent(v)){
                sum+=w;
                ds.unionBySize(u,v);
            }
        }
        return sum;
    }
};