#include <bits/stdc++.h>
using namespace std;

// Geek is going for n day training program. He can perform any one of these three activities Running, 
// Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve 
// all his skills, he can't do the same activity on two consecutive days. Help Geek to maximize his merit 
// points as you are given a 2D array of points points, corresponding to each day and activity.


// MEMOIZATION =>
int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if (day == 0){
        int maxi = 0;
        for (int task = 0; task < 3; task++){
            if (task != last)
                maxi = max(maxi, points[day][task]);
        }
        return maxi;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    int maxi = 0;
    for (int task = 0; task < 3; task++){
        if (task != last){
            int point = points[day][task] + f(day - 1, task, points, dp);
            maxi = max(point, maxi);
        }
    }
    return dp[day][last] = maxi;
}

// TABULATION =>
int f_tabulation(vector<vector<int>>&points){
    int n = points.size();
    vector<vector<int>>dp(n+1,vector<int>(4,-1));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    int x = max(points[0][0],points[0][1]);
    dp[0][3] = max(x,points[0][2]); // dp[0][3] = max(points[0][0],points[0][1],points[0][2]);
    for(int day = 1;day<n;day++){
        for(int last = 0;last<4;last++){
            dp[day][last] = 0;
            for(int task = 0;task<3;task++){
                if(task!=last){
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last],point);
                }
            }
    }
}
    return dp[n-1][3];
}

int main(){
    vector<vector<int>> points{{1, 2, 3}, {5, 10, 20}, {40, 90, 13}};
    int n = points.size();
    vector<vector<int>> dp(n + 1, vector<int>(4, -1));
    // cout<< f(n - 1, 3, points, dp);
    cout<< f_tabulation(points);
    return 0;
}