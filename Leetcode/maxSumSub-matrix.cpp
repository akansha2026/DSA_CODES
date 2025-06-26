#include <bits/stdc++.h>
using namespace std;

// setupIO
void setupIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int kadanesAlgo(vector<int> &nums){
    int curr = 0;
    int sum = INT_MIN;
    for(auto &x:nums){
        curr += x;
        sum = max(sum , curr);
        if(curr < 0) curr = 0;
    }
    return sum;
}

int maxRectangle(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n,vector<int>(m));
    for(int i=0; i<m; i++) dp[0][i] = matrix[0][i];

    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            dp[i][j] = matrix[i][j] + dp[i-1][j];
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++) cout << dp[i][j] << " " ;
    //     cout << endl;
    // }

    int maxSum = INT_MIN;
    for(int s=0; s<n; s++){
        for(int e=s; e<n; e++){
            vector<int> temp(m);
            for(int col=0; col<m; col++){
                int sum = dp[e][col];
                if(s-1 >= 0) sum -= dp[s-1][col];
                temp[col] = sum;
            }

            // Kadane's
            int sum = kadanesAlgo(temp);
            // cout << "Start: " << s << " End: "  << e << " Sum: " << sum << endl;
            // I already calculate the max matrix sum in the above loop
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

int maxSum(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dp(n,vector<int>(m));
    dp[0][0] = mat[0][0];
    for(int j=1; j<m; j++){
        dp[0][j] = dp[0][j-1] + mat[0][j];
    }
    for(int i=1; i<n; i++){
        dp[i][0] = dp[i-1][0] + mat[i][0];
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            dp[i][j] = mat[i][j] + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=i; k<n; k++){
                for(int l=j; l<m; l++){
                    // We have to handfle 4 cases like i-1 can be negative or j-1 can be negative
                    int sum = dp[k][l];
                    if(i > 0) sum -= dp[i-1][l];
                    if(j > 0) sum -= dp[k][j-1];
                    if(i > 0 && j > 0) sum += dp[i-1][j-1];
                    // here we find matrix that have max sum
                    ans = max(sum, ans);
                    cout << "i: " << i << " j: " << j << " k: " << k << " l: " << l << " sum: " << sum << endl;
                    cout << "sum: " << sum << endl;  
                }
            }
        }
    }
    return ans;
}

int32_t main() {
    setupIO();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n,vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> mat[i][j];
    }

    int ans = maxRectangle(mat);
    cout << ans << endl;
}