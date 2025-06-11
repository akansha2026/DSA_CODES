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

// Recursive way & Memoization
int maxProfit(int idx, int capacity, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
{
    int n = weight.size();

    // Base case
    if (idx == n || capacity == 0)
        return 0;

    if (dp[idx][capacity] != -1)
        return dp[idx][capacity];

    // Considering all scenarios
    if (weight[idx] <= capacity)
    {
        int take = value[idx] + maxProfit(idx + 1, capacity - weight[idx], weight, value, dp);
        int notTake = maxProfit(idx + 1, capacity, weight, value, dp);
        return dp[idx][capacity] = max(take, notTake);
    }
    else
        return dp[idx][capacity] = maxProfit(idx + 1, capacity, weight, value, dp);
}

// Tabulation method
int maxProfitUsingTabulation(int capacity, vector<int> &weight, vector<int> &value){

}         

int32_t main()
{
    setupIO();
    int n;
    cin >> n;
    vector<int> weight(n), value(n);
    int capacity;
    cin >> capacity;
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    for (int i = 0; i < n; i++)
        cin >> value[i];

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
    cout << maxProfit(0, capacity, weight, value, dp) << endl;
}