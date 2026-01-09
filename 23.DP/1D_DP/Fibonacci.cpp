#include <bits/stdc++.h>
using namespace std;

// Recursion => O(n!) Time and O(n) Space

int fib(int n) { // 0 1 1 2 3 5 8 13 21 34.......
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}


// Memoization => Time : O(n) and Space : O(n) recursive-stack-space & O(n) is the size of dp array

int fib1(int n, vector<int> &dp) { // 0 1 1 2 3 5 8 13 21 34.......
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib1(n - 1, dp) + fib1(n - 2, dp);
}

// Tabulation => Complexitites are same as memoization but no recursive stack space is used

int fib2(int n, vector<int> &dp) { // 0 1 1 2 3 5 8 13 21 34.......
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Space Optimized Solution =>

int fib3(int n) {
    int prev2 = 0;
    int prev = 1;
    for (int i = 2; i <= n; i++) {
        int curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int main() {
    int n = 5;
    vector<int> dp(n + 1, -1);
    cout << fib1(n, dp);
    cout << fib2(n, dp);
    cout << fib3(n);
    return 0;
}