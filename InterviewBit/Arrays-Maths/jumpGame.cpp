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

int jump(vector<int>& nums) {
    int jumps = 0;
    int farthest = 0;
    int end = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        // When we reach the end of the current jump range
        if (i == end) {
            jumps++;
            end = farthest;
        }
    }
    return jumps;
}


int32_t main() {
    setupIO();
    
}