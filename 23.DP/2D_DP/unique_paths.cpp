#include <bits/stdc++.h>
using namespace std;

//MEMOIZATION =>

int unique_ways(int m,int n,vector<vector<int>>&dp){
    if(m<0 or n<0) return 0;
    if(m==0 and n==0) return 1;
    if(dp[m][n]!=-1) return dp[m][n];
    int up_ways = unique_ways(m-1,n,dp) ;
    int left_ways = unique_ways(m,n-1,dp);
    return dp[m][n] = up_ways+left_ways; 
}

//TABULATION =>

int unique_ways2(int m,int n){
    vector<vector<int>>dp(m,vector<int>(n,1));
    int up_ways = 0;
    int left_ways = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        if(i==0 and j==0) dp[i][j] = 1;
        else {
        if(i>=1)  up_ways = dp[i-1][j];
        if(j>=1)  left_ways = dp[i][j-1];
        dp[i][j] = up_ways+left_ways;
        }
    }
    }
    return dp[m-1][n-1];
}

int main() {
    int m = 3;
    int n = 7;
    vector<vector<int>>dp(m,vector<int>(n,-1));
    // cout<<unique_ways(m-1,n-1,dp);
    cout<<unique_ways2(m-1,n-1);
    return 0;
}