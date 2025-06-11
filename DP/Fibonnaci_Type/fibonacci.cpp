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

// Recursion
int fib(int n){
    // Base case
    if(n == 0 || n == 1) return n;

    return fib(n - 1) + fib(n - 2);
}

// Check & Save (Memoization)
int fib(int n, vector<int> &dp){
    // Base case
    if(n == 0 || n == 1) return n;

    // Check
    if(dp[n] != -1) return dp[n];

    // Save and return
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int fib_tabulation(int n){
    vector<int> dp(n+1);

    // Base case
    dp[0] = 0;
    dp[1] = 1;

    // Solve remaining problem
    for(int i=2; i<=n; i++) dp[i] = dp[i-1] + dp[i-2];

    // Final answer
    return dp[n];
}

int fib_optimized(int n){
    if(n <= 1) return n;
    int a = 0, b = 1, c;
    for(int i=2; i<=n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int32_t main(){
    setupIO();
    
    // Start your code here
    clock_t start, end;
    int n = 46;
    start = clock();
    cout<<fib(n)<<endl;
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout<<"Time taken by recursion: "<<time_taken<<endl;

    start = clock();
    vector<int> dp(n+1, -1);
    cout<<fib(n, dp)<<endl;
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout<<"Time taken by memoization: "<<time_taken<<endl;

    start = clock();
    cout<<fib_tabulation(n)<<endl;
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout<<"Time taken by tabulation: "<<time_taken<<endl;
}