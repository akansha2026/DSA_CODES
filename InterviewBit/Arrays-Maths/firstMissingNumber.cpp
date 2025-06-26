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
int firstMissingNumber(vector<int> &nums){
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(nums[i] <= 0) nums[i] = n+1;
    }

    for(int i=0; i<n; i++){
        if(abs(nums[i]) > 0 && abs(nums[i]) <= n){
            int idx = abs(nums[i]) - 1;
            nums[idx] = - nums[idx];
        }
    }

    for(int i=0; i<n; i++){
        if(nums[i] > 0) return i+1;
    }
    return -1;
}

int32_t main() {
    setupIO();
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    cout << firstMissingNumber(nums) << endl;
}