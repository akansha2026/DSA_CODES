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

int repeatedNumber(vector<int> &nums){
    int n = nums.size();
    int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0;

    for(auto &num:nums){
        if(num == num1) cnt1++;
        else if(num == num2) cnt2++;
        else if(cnt1 == 0){
            num1 = num;
            cnt1 = 1;
        }
        else if(cnt2 == 0){
            num2 = num;
            cnt2 = 1;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0;
    cnt2 = 0;
    for(auto &num:nums){
        if(num == num1) cnt1++;
        else if(num == num2) cnt2++;
    }

    if(cnt1 > n/3) return num1;
    if(cnt2 > n/3) return num2;

    return -1;
}

int32_t main() {
    setupIO();
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    cout << repeatedNumber(nums) << endl;
}