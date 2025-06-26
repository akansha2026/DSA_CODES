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

int minMaxSum(vector<int> &nums){
    int n = nums.size();
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        mini = min(mini, nums[i]);
        maxi = max(maxi, nums[i]);
    }

    return (mini+maxi);
}

int32_t main() {
    setupIO();
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int ans = minMaxSum(nums);
    cout << ans << endl;
}