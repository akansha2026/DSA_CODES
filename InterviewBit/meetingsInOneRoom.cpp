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

int maxMeetings(vector<int>& start, vector<int>& end) {
    // Your code here
    int n = start.size();
    vector<vector<int>> meetings;
    for(int i=0; i<n; i++){
        meetings.push_back({start[i], end[i]});
    }

    sort(meetings.begin(), meetings.end(), [](vector<int> &a, vector<int> &b){
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    });
    // for(auto &v:meetings) cout << v[0] << " " << v[1] << endl;
    int cnt = 0;
    int last = -1;
    for(auto &meeting:meetings){
        if(meeting[0] > last){
            cnt++;
            last = meeting[1];
        }
    }
    return cnt;
}

int32_t main() {
    setupIO();
    int n;
    cin >> n;
    vector<int> startTime(n), endTime(n);
    for(int i=0; i<n; i++) cin >> startTime[i];
    for(int i=0; i<n; i++) cin >> endTime[i];

    int ans = maxMeetings(startTime, endTime);
    cout << ans << endl;
}