#include<bits/stdc++.h>
using namespace std;

void setupIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int climbStairs(int n) {
    int a = 1, b = 1, c;
    if(n == 0) return a;
    if(n == 1) return b;
    for(int i=2; i<=n; i++){
        c = a+ b;
        a = b;
        b = c;
    }
    return c;
}


int32_t main(){
    setupIO();
    
    // Start your code here
    
}