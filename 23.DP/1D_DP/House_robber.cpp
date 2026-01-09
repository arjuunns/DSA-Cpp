#include <bits/stdc++.h>
using namespace std;
/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it 
will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.*/

// MEMOIZATION =>

int rob(vector<int>&arr,int i,vector<int>&dp){  // largest sum subsequqence with non-adjacent elements
    if(i==0) return arr[0]; // if single element in an array , we will definitely pick it
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];
    int pick_house = arr[i] + rob(arr,i-2,dp);
    int not_pick_house = 0 + rob(arr,i-1,dp);
    return dp[i] = max(pick_house,not_pick_house);
}

// TABULATION =>

int rob(vector<int>&arr,vector<int>&dp){  // largest sum subsequqence with non-adjacent elements
    dp[0]=arr[0];
    int n = arr.size();
    for(int i = 1;i<n;i++){
        int pick = arr[i];
        if(i-2>=0) pick += dp[i-2];
        int not_pick = dp[i-1];
        dp[i] = max(pick,not_pick);
    }
    return dp[n-1];
}

int rob_space_optimized(vector<int>&arr){  // largest sum subsequqence with non-adjacent elements
    int n = arr.size();
    int prev = arr[0];
    int prev2 = 0;
    for(int i = 1;i<n;i++){
        int pick = arr[i] + prev2;
        int not_pick = prev;
        int curr = max(pick,not_pick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main() {
    vector<int>arr{2,1,1,2,5,6};
    int n = arr.size();
    vector<int>dp(n+1,-1);
    cout<<rob(arr,n-1,dp);
    cout<<rob(arr,dp);
    cout<<rob_space_optimized(arr);
    return 0;
}