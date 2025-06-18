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

int mergeIntervals(vector<vector<int>> &intervals){
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(),[](vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    });
    // cout << "Sorted intervals: "  << endl;
    // for(auto &interval:intervals){
    //     cout << interval[0] << " " << interval[1] << endl;
    // }
    int cnt = 0;
    int last = INT_MIN;
    // cout << "Stdio: " << endl;
    for(auto &interval:intervals){
        if(interval[0] >= last){
            // cout << interval[0] << " " << interval[1] << endl;
            cnt++;
            last = interval[1];
        }
    }
    return n - cnt;
}

int32_t main() {
    setupIO();
    int n;
    cin >> n;
    vector<vector<int>> intervals;
    for(int i=0; i<n; i++){
        int s, e;
        cin >> s >> e;
        intervals.push_back({s, e});
    }

    int ans = mergeIntervals(intervals);
    cout << ans << endl;
}