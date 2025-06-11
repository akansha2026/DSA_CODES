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

int rob(vector<int> &nums){
    int n = nums.size();
    if(n == 0) return 0;
    if(n == 1) return nums[0];

    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = nums[0];

    for(int i=2; i<=n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
    }

    return dp[n];
}


int32_t main(){
    setupIO();
    
    // Start your code here
    
}