#include <bits/stdc++.h>
using namespace std;

    int memoization(int *price , int n,int i,vector<vector<int>>&dp){
        if(!i) return n*price[0];
        if(dp[i][n]!=-1) return dp[i][n];
        int not_take = 0 + memoization(price,n,i-1,dp);
        int take = INT_MIN;
        int rodLen = i + 1;
        if(rodLen<=n) take = price[i] + memoization(price,n-rodLen,i,dp);
        return dp[i][n] = max(take,not_take);
    }
    
    int tabulation(int price[], int n) {
        int i = n;
        vector<vector<int>>dp(i,vector<int>(n+1,0));
        for(int i = 0;i<=n;i++) dp[0][i] = i*price[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int not_take = 0 + dp[j][i-1];
                int take = INT_MIN;
                int rodLen = i + 1;
                if(rodLen<=j) take = price[i] + dp[j-rodLen][i];
                dp[i][j] = max(take,not_take);
            }
        }
        return dp[i-1][n];
    }

    int spaceOptimized(int price[], int n) {
        int i = n;
        vector<int>prev(n+1,0),curr(n+1,0);
        for(int i = 0;i<=n;i++) prev[i] = i*price[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int not_take = 0 + prev[j];
                int take = INT_MIN;
                int rodLen = i + 1;
                if(rodLen<=j) take = price[i] + curr[j-rodLen];
                curr[j] = max(take,not_take);
            }
            prev = curr;
        }
        return prev[n];
    }

int main() {
    int n = 12;
    int i = n;
    vector<vector<int>>dp(i,vector<int>(n+1,-1));
    // return memoization(price,n,i-1,dp);
    return 0;
}