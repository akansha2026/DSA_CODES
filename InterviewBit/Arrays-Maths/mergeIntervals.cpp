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

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    int n = intervals.size();
    vector<vector<int>> ans;

    int i = 0;
    while (i < n)
    {
        if (i + 1 < n && intervals[i + 1][0] > intervals[i][1])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            int last = intervals[i][1];
            int start = intervals[i][0];

            while (i + 1 < n && intervals[i + 1][0] <= last)
            {
                last = max(last, intervals[i+1][1]);
                start = min(start, intervals[i+1][0]);
                i++;
            }
            ans.push_back({start, last});
        }
        i++;
    }
    return ans;
}

int32_t main()
{
    setupIO();
    int n;
    cin >> n;
    vector<vector<int>> intervals;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        intervals.push_back({s, e});
    }

    vector<vector<int>> ans = merge(intervals);
    for (auto &v : ans)
    {
        cout << v[0] << " " << v[1] << endl;
    }
}