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

int maxPlatform(vector<int> &arrive, vector<int> &depart)
{
    int n = arrive.size();
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    int cnt = 0;
    int i = 0, j = 0;
    int ans = INT_MIN;

    while (i < n && j < n)
    {
        if (arrive[i] <= depart[j])
        {
            cnt++;
            i++;
        }
        else
        {
            cnt--;
            j++;
        }
        if(cnt > ans) ans = cnt;
    } 
    return ans;
}

int32_t main()
{
    setupIO();
    int n;
    cin >> n;
    vector<int> arr(n), dep(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        cin >> dep[i];

    cout << maxPlatform(arr, dep) << endl;
}