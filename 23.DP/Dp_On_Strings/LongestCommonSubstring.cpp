#include <bits/stdc++.h>
using namespace std;
int longestCommonSubString(string s1, string s2, int i, int j, vector<vector<int>> &dp, int ans){
    if (i == 0 or j == 0) return ans;
    if (dp[i][j] != -1) return dp[i][j];
    int same = ans;
    if (s1[i - 1] == s2[j - 1]) same = longestCommonSubString(s1, s2, i - 1, j - 1, dp, ans+1);
    int diff1 = longestCommonSubString(s1,s2,i-1,j,dp,ans);
    int diff2 = longestCommonSubString(s1,s2,i,j-1,dp,ans);
    return max(same,max(diff1,diff2));
}

int tabulation(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // shifting of index
    for (int i = 0; i <= m; i++) dp[i][0] = 0;
    for (int j = 0; j <= n; j++) dp[0][j] = 0;
    int ans = 0;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (text1[i - 1] == text2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1]; // if matches, move both backward
                ans = max(ans,dp[i][j]);
        }
            else dp[i][j] = 0;
        }
    }
    return ans;
}

int main()
{
    string s1 = "abcjklp";
    string s2 = "acjkp";
    int ans = 0;
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // ans = longestCommonSubString(s1, s2, n, m, dp, ans);
    ans = tabulation(s1, s2);
    cout << ans;
    return 0;
}