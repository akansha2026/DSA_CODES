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

vector<int> maxProfitInJobSequencing(vector<int> &deadline, vector<int> &profit)
{
    int n = profit.size();
    vector<vector<int>> assignment;
    int lastDeadline = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        assignment.push_back({profit[i], deadline[i]});
        lastDeadline = max(lastDeadline, deadline[i]);
    }
    sort(assignment.begin(), assignment.end(), [](vector<int> &a, vector<int> &b){
        return a[0] >= b[0];
    });
    vector<bool> schedule(lastDeadline + 1, false);
    vector<int> posn(lastDeadline + 1);
    for (int i = 0; i <= lastDeadline; i++)
        posn[i] = i;

    int maxProfit = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int p = assignment[i][0];
        int d = assignment[i][1];
        int idx = posn[d];
        while(idx >= 1 && schedule[idx] == true) idx--;
        if(idx >= 1){
            schedule[idx] = true;
            posn[d] = idx;
            maxProfit += p;
            cnt++;
            cout << maxProfit << endl;
        }
    }

    return {cnt, maxProfit};
}

int32_t main()
{
    setupIO();
    int n;
    cin >> n;
    vector<int> deadline(n), profit(n);
    for (int i = 0; i < n; i++)
    {
        cin >> deadline[i] >> profit[i];
    }

    vector<int> ans = maxProfitInJobSequencing(deadline, profit);
    cout << ans[0] << " "  << ans[1] << endl;
}