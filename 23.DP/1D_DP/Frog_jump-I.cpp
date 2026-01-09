#include <bits/stdc++.h>
using namespace std;
/* Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps.
A height[N] array is also given. Whenever the geek jumps from stair i to stair j,
the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference.
return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1*/

// MEMOIZATION =>

int minimumEnergy(vector<int> &height, int i, vector<int> &dp) { // assuming this function gives me the cost from n to 0 jumps 
    if (!i) return 0;
    if (dp[i] != -1) return dp[i];
    int w1 =abs(height[i] - height[i - 1]) + minimumEnergy(height, i - 1, dp) ;
    int w2 = INT_MAX;
    if (i > 1) w2 =abs(height[i] - height[i - 2]) +  minimumEnergy(height, i - 2, dp) ; // 1st index se -1 index pe kud jayega varna
    return dp[i] = min(w1, w2);
}

// TABULATION =>
int min_energy_tabulation(vector<int>&heights,vector<int>&dp){
    dp[0]=0;
    int n = heights.size();
    for(int i = 1;i<n;i++){
        int w1 = dp[i-1]+abs(heights[i]-heights[i-1]);
        int w2 = INT_MAX;
        if(i>1) w2 = dp[i-2]+abs(heights[i]-heights[i-2]);
        dp[i]=min(w1,w2);
    }
    return dp[n-1];
}

// Space Optimization => 

int dp3(vector<int>&heights){
    int prev=0;
    int prev2=0;
    int n = heights.size();
    for(int i = 1;i<n;i++){
        int w1 = prev + abs(heights[i]-heights[i-1]);
        int w2 = INT_MAX;
        if(i>1) w2 = prev2 + abs(heights[i]-heights[i-2]);
        int curr = min(w1,w2);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main(){
    vector<int>heights{10,20,30,10};
    int n = heights.size();
    vector<int>dp(n+1,-1);
    cout<<minimumEnergy(heights,n-1,dp);
    cout<<min_energy_tabulation(heights,dp);
    cout<<dp3(heights);
    return 0;
}