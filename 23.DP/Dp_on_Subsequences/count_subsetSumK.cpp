#include <bits/stdc++.h>
using namespace std;
// int f(vector<int> &arr, int n, int target, vector<vector<int>> &dp) { // when elements are starting from 0;

//     if (!target) return 1;
//     if (!n) return arr[0] == target;
//     if (dp[n][target] != -1) return dp[n][target];
//     int notTake = f(arr, n - 1, target, dp);
//     int take = 0;
//     if (target > arr[n]) {
//         take = f(arr, n - 1, target - arr[n], dp);
//     }
//     return dp[n][target] = take + notTake;
// }
const int MOD = 1e9 + 7;
int memoization(vector<int> &arr, int n, int target, vector<vector<int>> &dp) {   // when elements are starting from 0;

    if (!n) {
        if(!target and arr[0]==0) return 2;
        if(!target or arr[0]==target) return 1;
        return 0;
    };
    if (dp[n][target] != -1) return dp[n][target];
    int notTake = memoization(arr, n - 1, target, dp);
    int take = 0;
    if (target > arr[n]) take = memoization(arr, n - 1, target - arr[n], dp);
    return dp[n][target] = (take + notTake)%MOD; // to handle larger answers
}
int main(){
    vector<int> arr{1,2,3}; //{3,4},{1,2,3,1},{4,1,2},{2,3,2}
    int n = arr.size();
    int target = 7;
    // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    if(arr[0]==0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if(arr[0]!=0) dp[0][arr[0]] = 1;
    for(int i = 1;i<n;i++){
        for(int sum = 0;sum<=target;sum++){
            int notTake = dp[i - 1][target];
            int take = 0;
                if (sum >= arr[i]) take = dp[i - 1][sum-arr[i]];
                dp[i][sum] = (take + notTake)%MOD; // to handle larger answers
        }
    }
    cout<<dp[n - 1][target];
    return 0;
}