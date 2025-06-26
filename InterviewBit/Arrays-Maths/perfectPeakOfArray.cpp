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


bool isExist(vector<int> &nums){
    int n = nums.size();
    vector<int> greater(n, INT_MIN), smaller(n, INT_MAX);
    for(int i=1; i<n; i++){
        greater[i] = max(greater[i-1], nums[i-1]);
    }

    for(int i=n-2; i>=0; i--){
        smaller[i] = min(smaller[i+1], nums[i+1]);
    }
    

    for(int i=1; i<n-1; i++){
        // cout << greater[i] << " " << smaller[i] << endl;
        if(nums[i] > greater[i] && nums[i] < smaller[i]) {
            // cout << "Peak Number is: " << greater[i] << endl;
            return true;
        }
    }
    return false;
}

int32_t main() {
    setupIO();
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    bool ans = isExist(nums);
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}