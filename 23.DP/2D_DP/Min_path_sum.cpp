#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION =>
    int helper(vector<vector<int>>& grid,int n,int m,vector<vector<int>>&dp){
        if(n==0 and m==0) return grid[0][0];
        if(n<0 or m<0) return INT_MAX;
        if(dp[n][m]!=-1) return dp[n][m];
        int left = grid[n][m] + helper(grid,n,m-1,dp);
        int up = grid[n][m] + helper(grid,n-1,m,dp);
        return dp[n][m] = min(up,left);
    }
    
// TABULATION =>
    int helper2(vector<vector<int>>& grid,int n,int m){
        vector<vector<int>>dp(n,vector<int>(m));
        dp[0][0] = grid[0][0];
        for(int i = 1;i<n;i++){
            for(int j= 1;j<m;j++){
               int left = grid[n][m]+dp[i][j-1];
               int up = grid[n][m]+dp[i-1][j];
               dp[i][j] = min(left,up);
            }
        }
        return dp[n-1][m-1];
    }

// SPACE OPTIMIZATION => carry current and prev rows prev = dp[i-1][j] and curr = dp[i][j-1]

int helper3(vector<vector<int>>& grid,int n,int m){ // space optmization
        vector<int>prev(m,0);
        for(int i = 0;i<n;i++){
            vector<int>curr(m,0);
            for(int j= 0;j<m;j++){
            if(!i and !j) curr[j] = grid[0][0];
            else{
                int up = grid[i][j];
                if(i>=1) up+=prev[j];
                else up += 1e8;
                int left = grid[i][j];
                if(j>=1) left+=curr[j-1];
                else left += 1e8;
                curr[j] = min(up,left);
            }
        }
        prev = curr;
        }
        return prev[m-1];
    }

int main() {
        vector<vector<int>>grid{{1,2,3},{4,5,3},{5,8,1}};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        // cout<< helper(grid,n-1,m-1,dp);
        cout<< helper3(grid,n,m);
    return 0;
}