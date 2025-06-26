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

bool sumExistInRange(double l, double r, vector<double> &nums){
    int n = nums.size();

    sort(nums.begin(), nums.end());
    int i=0, j=1, k=2;
    if(n < 3) return false;

    while(i < n && j < n && k < n){
        cout << "i: " << i << " j: " << j << " k: " << k << endl;
        cout << "nums[i]: " << nums[i] << " nums[j]: " << nums[j] << " nums[k]: " << nums[k] << endl;
        double sum = nums[i] + nums[j] + nums[k];
        if(sum < r && sum > l) return true;
        else if(sum < l){
            if((j-i-1) != 0) i++;
            else if((k-j-1) != 0) j++;
            else k++;
        }
        else return false;
    }
    return false;
}

int32_t main() {
    setupIO();
    int n;
    cin >> n;
    double l, r;
    cin >> l >> r;
    vector<double> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    bool isExist = sumExistInRange(l, r, nums);
    if(isExist) cout << "YES" << endl;
    else cout << "NO" << endl;
}