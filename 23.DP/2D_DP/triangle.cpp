#include <bits/stdc++.h>
using namespace std;

//MEMOIZATION =>

int memoize(vector<vector<int>>& triangle,int i,int j,int n,vector<vector<int>>&dp){
       if(i==n-1) return triangle[i][j];
       if(dp[i][j]!=-1) return dp[i][j];
       long down = triangle[i][j] + memoize(triangle,i+1,j,n,dp);
       long diagonal = triangle[i][j] + memoize(triangle,i+1,j+1,n,dp);
       return dp[i][j] = min(down,diagonal);
    }

//  TABULATION => remember that tabulation me memoization se ulta chlta hai flow

    int tabulate(vector<vector<int>>& triangle,int i,int j,int n){
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[n-1][j] = triangle[n-1][j]; // filing out the last levels
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,diagonal);
            }
        }
        return dp[0][0];
    }
int main() {
        vector<vector<int>>triangle{{1},{1,2},{3,5,7},{6,10,3,9}};
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        cout << memoize(triangle,0,0,n,dp);
        cout << tabulate(triangle,0,0,n);
    
    return 0;
}