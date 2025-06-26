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

vector<int> maxSubArray(vector<int> &nums){
    int n = nums.size();

    vector<int> ans;
    vector<bool> check(n);
    check[0] = true;
    int firstFalse = -1, lastFalse = -1;
    for(int i=1; i<n; i++){
        if(nums[i] >= nums[i-1]) check[i] = true;
        else{
            if(firstFalse == -1) firstFalse = i;
            lastFalse = i;
            check[i] = false;
        }
    }
    if(firstFalse == -1) return 0;
    for(int i=firstFalse-1; i<=lastFalse; i++) ans.push_back(i);
    return ans;
}

int32_t main() {
    setupIO();
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    vector<int> ans = maxSubArray(nums);
    for(auto &x:ans) cout << x << " ";
    cout << endl;
}