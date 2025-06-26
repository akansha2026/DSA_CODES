#include <bits/stdc++.h>
using namespace std;

// setupIO
void setupIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

struct comp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            if(a[1] == b[1]) return a[2] > b[2];
            return a[1] > b[1]; // Min-heap based on the 2nd element (index 1)
        }
        // priority_queue will look like
        /* a is first and b is second and c is third and
        queue follow First In First Out'
        pq = [[a],[b],[c]]
        */
    };

    vector<int> averageWaitingTime(vector<vector<int>> &processes) {
        int n = processes.size();
        for (int i = 0; i < n; i++) {
            processes[i].push_back(i);
        }
        // Sort processes by arrival time, and then by burst time
        sort(processes.begin(), processes.end());
        for(auto &p:processes) cout << p[0] << " " << p[1] << " " << p[2] << endl;

        // Find the curr time initially for arraival time
        long long currTime = 0;
        vector<int> ans;
        // If comparator returns true means

        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        int idx = 0;
        while (idx < n || !pq.empty()) {
            while (idx < n && processes[idx][0] <= currTime) {
                pq.push(processes[idx]);
                idx++;
            }

            if(pq.empty()){
                currTime = processes[idx][0];
            }

            else{
                vector<int> process = pq.top();
                cout << process[0] << " " << process[1] << " " << process[2] << endl;
                pq.pop();
                // We will execute this process and update the currTime
                currTime += process[1];
                ans.push_back(process[2]);
            }
        }
        return ans;
    }

int32_t main()
{
    setupIO();
    int n;
    cin >> n;
    vector<int> bt(n), at(n);
    vector<vector<int>> processes;
    for (int i = 0; i < n; i++)
    {
        cin >> at[i] >> bt[i];
        processes.push_back({at[i], bt[i]});
    }

    vector<int> ans = averageWaitingTime(processes);
    for(auto &x:ans) cout << x <<  " ";
    cout << endl;
}