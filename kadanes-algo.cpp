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


int32_t main(){
    setupIO();
    
    // Start your code here
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &x: arr) cin >> x;

    // Maximum Sum
    int maxSum = INT_MIN;
    int start = 0, end = 0;

    // Brute force - 01 : T(N) = O(N^3)
    for(int left = 0; left < n; left++){
        for(int right = left; right < n; right++){
            int sum = 0;
            for(int i = left; i <= right; i++) sum += arr[i];
            if(sum > maxSum) {
                maxSum = sum;
                start = left;
                end = right;
            }
        }
    }
    cout << maxSum << endl;
    cout << (end - start + 1) << endl;

    // Resetting maxSum
    maxSum = INT_MIN;
    start = 0, end = 0;

    // Brute force - 02 : T(N) = O(N^2)
    // We will use prefix sum
    vector<int> pre(n);
    pre[0] = arr[0];
    for(int i=1; i<n; i++) pre[i] = pre[i-1] + arr[i];
    for(int left = 0; left < n; left++){
        for(int right = left; right < n; right++){
            int sum = (left == 0) ? pre[right] : (pre[right] - pre[left - 1]);
            if(sum > maxSum) {
                maxSum = sum;
                start = left;
                end = right;
            }
        }
    }
    cout << maxSum << endl;
    cout << (end - start + 1) << endl;

    // Resetting maxSum
    maxSum = INT_MIN;
    start = 0, end = 0;
    int currStart = 0;

    // Kadane's Algo : T(N) = O(N)
    int currSum = 0;
    for(int i=0; i<n; i++){
        currSum += arr[i];

        // Is current sum becomes negative then there is no need to expand this subarray that is why we weill neglect the curr subarray and start rom begining
        if(currSum < 0) {
            currSum = 0;
            currStart = i + 1;
        }

        if(currSum > maxSum) {
            maxSum = currSum;
            start = currStart;
            end = i;
        }
    }
    cout << maxSum << endl;
    cout << (end - start + 1) << endl;

}