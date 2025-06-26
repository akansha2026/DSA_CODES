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

void moveZeroesToEnd(vector<int> &nums) {
    int n = nums.size();
    int i = 0, j = 0;


    while(i < n){
        if(nums[i] != 0){
            // Swap 
            swap(nums[j], nums[i]);
            i++;
            j++;
        }else{
            i++;
        }
    }
    
    return nums;
}

int32_t main() {
    setupIO();
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    moveZeroesToEnd(nums);
    for(auto &x:nums) cout << x << " ";
    cout << endl;
}