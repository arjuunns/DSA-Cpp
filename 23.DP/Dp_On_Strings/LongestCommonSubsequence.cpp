#include <bits/stdc++.h>
using namespace std;

int memoization(string text1, string text2, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 or j == 0)
        return 0; // we did shifting of index, so ith idx represents (i-1)th indx now
    if (dp[i][j] != -1)
        return dp[i][j];
    if (text1[i - 1] == text2[j - 1])
        return dp[i][j] = 1 + memoization(text1, text2, i - 1, j - 1, dp); // if matches, move both backward
    else
        return dp[i][j] = max(memoization(text1, text2, i - 1, j, dp), memoization(text1, text2, i, j - 1, dp));
}

int tabulation(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // shifting of index
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1]; // if matches, move both backward
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int spaceOptimized(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                curr[j] = 1 + prev[j - 1]; // if matches, move both backward
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[n];
}

int main()
{
    int n = 12;
    int i = n;
    string text1 = "abcd";
    string text2 = "abde";
    vector<vector<int>> dp(i, vector<int>(n + 1, -1));
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1)); // shifting of index
    return memoization(text1, text2, m, n, dp);
    // return memoization(price,n,i-1,dp);
    return 0;
}