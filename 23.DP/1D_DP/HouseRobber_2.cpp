#include <bits/stdc++.h>
using namespace std;
 // array is circular this time which means first and last elements are also neighbours.

 // MEMOIZATION =>
    int helper(vector<int>&nums,int i,int j,vector<vector<int>>&dp){ // gets maximum money that can be robbed between ith and jth house both inclusive
        if(j == i) return nums[i];
        if(j < i) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int rob = nums[j] + helper(nums,i,j-2,dp);
        int leave = 0 + helper(nums,i,j-1,dp);
        return dp[i][j] = max(rob,leave);
    }

// TABULATION =>

int main() {
        vector<int>nums{1,2,3,1};
        int n = nums.size();
        if(n==1) return nums[0];
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int left_to_right = helper(nums,0,n-2,dp);
        int right_to_left = helper(nums,1,n-1,dp);
        return max(left_to_right,right_to_left);
    
    return 0;
}