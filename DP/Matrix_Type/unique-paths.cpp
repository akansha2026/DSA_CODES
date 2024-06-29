#include<bits/stdc++.h>
using namespace std;

void setupIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int countPaths(int row, int col, int m, int n, vector<vector<int>> &dp){
    if(row == m || col == n) return 1;

    if(dp[row][col] != -1) return dp[row][col];

    int down = countPaths(row + 1, col, m, n, dp);
    int right = countPaths(row, col + 1, m, n, dp);

    return dp[row][col] = down + right;
}

int tabulation(int m, int n){
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    
    // last row
    for(int i=1; i<=n; i++) dp[m][i] = 1;
    for(int i=1; i<=m; i++) dp[i][n] = 1;

    for(int row = m-1; row >= 1; row--){
        for(int col = n-1; col >= 1; col--){
            dp[row][col] = dp[row+1][col] + dp[row][col + 1];
        }
    }

    return dp[1][1];
}

int optimized(int m, int n){
    vector<int> curr(n+1), prev(n+1, 1);
    for(int row = m-1; row >= 1; row--){
        for(int col = n; col >= 1; col--){
            if(col == n) curr[col] = 1;
            else curr[col] = prev[col] + curr[col + 1];
        }
        prev = curr;
    }
    return curr[1];
}

int uniquePaths(int m, int n) {
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // return countPaths(1, 1, m, n, dp);
    return tabulation(m, n);
}


int32_t main(){
    setupIO();
    
    // Start your code here
    
}