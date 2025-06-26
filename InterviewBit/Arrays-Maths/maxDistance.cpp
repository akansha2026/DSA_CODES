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

int maxDistance(vector<int> &arr){
    vector<vector<int>> nums;
    int n = arr.size();
    for(int i=0; i<n; i++){
        nums.push_back({arr[i], i});
    }

    sort(nums.begin(), nums.end());
    // for(auto &v:nums){
    //     cout << v[0] << " " << v[1] << endl;
    // }
    int mini = INT_MAX;
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        mini = min(mini, nums[i][1]);
        ans = max(ans, nums[i][1] - mini);
    }
    return ans;
}

int32_t main() {
    setupIO();
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int ans = maxDistance(nums);
    cout << ans << endl;
}