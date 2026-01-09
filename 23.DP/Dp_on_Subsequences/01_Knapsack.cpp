#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION =>

int findMaxWeightMemoization(vector<int> &values, vector<int> &weights, int n, int w,vector<vector<int>>&dp){ // time : O(NxW) | space : O(N*W)+O(N)
   if(!n){
	   if(weights[0]<=w) return values[0];
	   else return 0;
   }
   if(dp[n][w]!=-1) return dp[n][w];
   int not_take = 0 + findMaxWeightMemoization(values,weights,n-1,w,dp);
   int take = INT_MIN;
   if(weights[n]<=w) take = values[n] + findMaxWeightMemoization(values,weights,n-1,w-weights[n],dp);
   return dp[n][w] = max(take,not_take);
}

// TABULATION =>

int findMaxWeightTabulation(vector<int> &values, vector<int> &weights, int n, int w){
   vector<vector<int>>dp(n,vector<int>(w+1,0));
	for(int i = weights[0];i<=w;i++){
		dp[0][i] = values[0];
	}
	for(int i = 1;i<n;i++){
		for(int weight = 0;weight<=w;weight++){
			int not_take = 0 + dp[i-1][weight];
   			int take = INT_MIN;
   			if(weights[i]<=weight) take = values[i] + dp[i-1][weight-weights[i]];
   			dp[i][weight] = max(take,not_take);
		}
	}
	return dp[n-1][w];
}

// SPACE OPTIMIZATION 2-ARRAY =>

int findMaxWeightSpaceOptimized(vector<int> &values, vector<int> &weights, int n, int w){
   vector<int>prev(w+1,0),curr(w+1,0);
	for(int i = weights[0];i<=w;i++) prev[i] = values[0];
	for(int i = 1;i<n;i++){
		for(int weight = 0;weight<=w;weight++){
			int not_take = 0 + prev[weight];
   			int take = INT_MIN;
   			if(weights[i]<=weight) take = values[i] + prev[weight-weights[i]];
   			curr[weight] = max(take,not_take);
		}
        prev = curr;
	}
	return prev[w];
}

//  SPACE OPTIMIZATION SINGLE ARRAY =>

int findMaxWeightSpaceOptimizedII(vector<int> &values, vector<int> &weights, int n, int w){ // damn => only works jab inner loop ulta chlaoge
   vector<int>prev(w+1,0);
	for(int i = weights[0];i<=w;i++) prev[i] = values[0];
	for(int i = 1;i<n;i++){
		for(int weight = w;weight>=0;weight--){
			int not_take = 0 + prev[weight];
   			int take = INT_MIN;
   			if(weights[i]<=weight) take = values[i] + prev[weight-weights[i]];
   			prev[weight] = max(take,not_take);
		}
	}
	return prev[w];
}

int main() {
    vector<int>weights{1,2,4,5};
    vector<int>values{5,4,8,6};
    int w = 5;
    int n = weights.size();
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
	cout << findMaxWeightMemoization(values,weights,n-1,w,dp) << endl;
	cout << findMaxWeightTabulation(values,weights,n-1,w) << endl;
	cout << findMaxWeightSpaceOptimized(values,weights,n-1,w) << endl;
	cout << findMaxWeightSpaceOptimizedII(values,weights,n-1,w) << endl;
    return 0;
}