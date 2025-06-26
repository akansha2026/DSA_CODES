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

vector<int> repeatedNumber(const vector<int> &nums) {
    int n = nums.size();
    int a = 0, b = 0;
    int val = 0;
    for(int i=0; i<n; i++){
        val = val^nums[i];
        val = val ^ (i + 1);
    }
    
    int idx = 0;
    for(int i=0; i<32; i++){
        if((val & (1 << i)) != 0) {
            idx = i;
            break;
        }
    }
    
    for(int i=0; i<n; i++){
        if((nums[i] & (1 << idx)) != 0) a ^= nums[i]; // belongs to set A
        else b ^= nums[i]; // belongs to set B
        
        if(((i+1) & (1 << idx)) != 0) a ^= (i+1); // belongs to set A
        else b ^= (i + 1); // belongs to set B
    }
    
    bool isPresent = false;
    for(int i=0; i<n; i++){
        if(nums[i] == a) isPresent = true;
    }
    
    // We have to maintain the order of missing and repeated
    if(isPresent) return {a, b};
    return {b, a};
}


Repeat and Missing Number Array

int32_t main() {
    setupIO();
    
}