
#include <bits/stdc++.h>
using namespace std;
int minDifference(int arr[], int n) {
    int totSum = 0;
    for (int i = 0; i < n; i++) totSum += arr[i];
    vector<vector<bool>> dp(n, vector<bool>((totSum + 1)/2, false)); // saves space and prevents repetitive subsets 
    for (int i = 0; i < n; i++) dp[i][0] = true;
    if (arr[0] <= totSum) dp[0][arr[0]] = true;
    for (int ind = 1; ind < n; ind++){
        for (int target = 1; target <= totSum; target++){
            bool notTaken = dp[ind - 1][target];
            bool taken = false;
            if (arr[ind] <= target) taken = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = notTaken or taken;
        }
    }
    int mini = 1e9;
    for (int i = 0; i <= totSum; i++){
        if (dp[n - 1][i] == true) {
            int diff = abs(totSum - 2 * i);
            mini = min(mini, diff);
        }
    }
    return mini;
};

int main()
{

    int arr[6] = {1,2,3,4,5,6};
    cout<<minDifference(arr,6); 
    return 0;
}
