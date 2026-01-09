#include <bits/stdc++.h>
using namespace std;
bool f(vector<int> &arr, int n, int target, vector<vector<int>> &dp) { 

    if (!target) return true;
    if (!n) return arr[0] == target;
    if (dp[n][target] != -1) return dp[n][target];
    bool notTake = f(arr, n - 1, target, dp);
    bool take = false;
    if (target > arr[n]) {
        take = f(arr, n - 1, target - arr[n], dp);
    }
    return dp[n][target] = take or notTake;
}
int main(){
    vector<int> arr{1, 2, 3, 4, 1, 2};
    int n = arr.size();
    int target = 7;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    // dp[n][target+1];
    // dp[n][0] = true;
    // for(i->0 to n) dp[0][0],dp[1][0],dp[2][0] =true;
    // dp[0][arr[0]] = true;


    f(arr, n - 1, target, dp) ? (cout << "Yes") : (cout << "No");
    return 0;
}