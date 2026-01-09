#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  const int MOD = 1e9+7;
    int f(int n,int d,int target,vector<int>&arr,vector<vector<int>>&dp){
      if(!n){ // to handle cases when there might be zero as an element, eg {0,0,1} here {1,0}, {0,1}, {1,0,1} ,{1,0,0}..... are also valid
          if(!target and arr[0]==0) return 2;
          if(!target or arr[0]==target) return 1;
          return 0;
      }
      if(dp[n][target]!=-1) return dp[n][target];
      int not_take = f(n-1,d,target,arr,dp);
      int take = 0;
      if(arr[n]<=target) take = f(n-1,d,target-arr[n],arr,dp);
      return dp[n][target] = (take+not_take)%MOD;
  }
        int countPartitions(int n, int d, vector<int>& arr) {
        int tSum = 0;
        for(auto i : arr) tSum+=i;
        int target = (tSum+d);  // you can also take tSum-d
        
        if(target%2 or tSum<d) return 0; 
        else target/=2;
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        if(arr[0]==0) dp[0][0] = 2;
        else dp[0][0] = 1;
        if(arr[0]<=target and arr[0]!=0) dp[0][arr[0]] = 1;
        for(int i = 1;i<n;i++){
            for(int sum = 0;sum<=target;sum++){
                int not_take = dp[i-1][sum];
                int take = 0;
                if(arr[i]<=sum) take = dp[i-1][sum-arr[i]]; 
                dp[i][sum] = (take+not_take)%MOD;
            }
        }
        return dp[n-1][target];
    }
};
