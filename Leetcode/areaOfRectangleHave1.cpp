#include <bits/stdc++.h>
using namespace std;

// setupIO
void setupIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// int matrixSum(int i1, int j1, int i2, int j2, vector<vector<int>>& matrix){
//     cout << "MaxSum" << endl;
//     int ans = 0;
//     for(int i=i1; i<=i2; i++){
//         for(int j=j1; j<=j2; j++){
//             ans += matrix[i][j];
//         }
//     }
//     return ans;
// }

// Now I will use kadane's algorithm to find the maximum sum of a sub-matrix
int maximalRectangleByKadane(vector<vector<int>> &mat){
    int n = mat.size(), m = mat[0].size();

    vector<vector<int>> dp(n, vector<int>(m));
    for(int j=0; j<m; j++){
        dp[0][j] = mat[0][j];
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            dp[i][j] = dp[i-1][j] + mat[i][j];
        }
    }

    for(int s=0; s<n; s++){
        for(int e=s; e<n; e++){
            int i=0, j=0;
            int start = -1, end = -1;
            int curr = 0, sum = 0;
            while(i < m && j < m){
                
            }
        }
    }
}


// Brute force approach to find the maximal rectangle of 1s in a binary matrix
// Time Complexity: O(n^2 * m^2)
// Space Complexity: O(n * m)
// where n is the number of rows and m is the number of columns in the matrix.
int maximalRectangle(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = mat[0][0];
    for (int j = 1; j < m; j++)
    {
        dp[0][j] = dp[0][j - 1] + mat[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + mat[i][0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = mat[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = i; k < n; k++)
            {
                for (int l = j; l < m; l++)
                {
                    // We have to handfle 4 cases like i-1 can be negative or j-1 can be negative
                    int sum = dp[k][l];
                    if (i > 0)
                        sum -= dp[i - 1][l];
                    if (j > 0)
                        sum -= dp[k][j - 1];
                    if (i > 0 && j > 0)
                        sum += dp[i - 1][j - 1];
                    if (sum == (k - i + 1) * (l - j + 1))
                        ans = max(sum, ans);
                }
            }
        }
    }
    return ans;
}

int32_t main()
{
    setupIO();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
    for (auto &v : mat)
    {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
    cout << maximalRectangle(mat) << endl;
}