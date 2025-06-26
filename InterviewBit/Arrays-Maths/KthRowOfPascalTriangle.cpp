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
vector<int> getRow(int rowIndex) {
    int numRows = rowIndex + 1;
    vector<vector<int>> dp(numRows);
    int m = 1;
    for(int i=0; i<numRows; i++){
        for(int j=0; j<m; j++){
            if(j == 0 || j == m-1) dp[i].push_back(1);
            else dp[i].push_back(dp[i-1][j-1] + dp[i-1][j]);
        }
        m++;
    }
    return dp[rowIndex];
}
int32_t main() {
    setupIO();
    int n;
    cin >> n;
    vector<int> ans = getRow(n);
    for(auto &x:ans) cout << x << " ";
    cout << endl;
}