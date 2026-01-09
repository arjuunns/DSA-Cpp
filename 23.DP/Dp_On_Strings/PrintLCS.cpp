#include <bits/stdc++.h>
using namespace std;
string memoization(string text1, string text2, int i, int j, vector<vector<string>> &dp) {
    if (i == 0 or j == 0) return ""; // we did shifting of index, so ith idx represents (i-1)th indx now
    if (dp[i][j] != "%") return dp[i][j];
    if (text1[i - 1] == text2[j - 1]) return dp[i][j] = memoization(text1, text2, i - 1, j - 1, dp)+text1[i-1]; // if matches, move both backward
    else return dp[i][j] = max(memoization(text1, text2, i - 1, j, dp), memoization(text1, text2, i, j - 1, dp));
}

int main() {
    string text1 = "abcdgn";
    string text2 = "abden";
    int m = text1.size();
    int n = text2.size();
    // vector<vector<string>> dp(m + 1, vector<string>(n + 1, "%")); // shifting of index
    // cout<<memoization(text1,text2,m,n,dp);
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // shifting of index
    for (int i = 0; i <= m; i++) dp[i][0] = 0;
    for (int j = 0; j <= n; j++) dp[0][j] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1]; // if matches, move both backward
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << dp[m][n];
    return 0;
}