#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION =>

    int helper(vector<int>&heights,int i,vector<int>&dp,int k){
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        int minCost = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j >= 0) {
            int jumpCost = helper(heights,i-j,dp,k) + abs(heights[i]-heights[i-j]);
            minCost = min(minCost,jumpCost);
            }
        }
        return dp[i] = minCost;
    }

// TABULATION =>

    int tabulation(vector<int>&heights,int k){
        int n = heights.size();
        vector<int>dp(n+1,0);
        dp[0] = 0;
        for(int i = 1 ;i< n; i++){
           int minCost = INT_MAX;
           for(int j = 1;j<=k;j++){
               if(i-j >=0){
                int jumpCost = dp[i-j] + abs(heights[i]-heights[i-j]);
                minCost = min(minCost,jumpCost);
               }
           }
           dp[i] = minCost;
        }
        return dp[n-1];
    }
int main() {
    vector<int>heights{10,20,30,40,20,10};
    int n = heights.size();
    vector<int>dp(n+1,-1);
    int k = 3;
    cout << helper(heights,n-1,dp,k);
    cout << tabulation(heights,k);
    return 0;
}