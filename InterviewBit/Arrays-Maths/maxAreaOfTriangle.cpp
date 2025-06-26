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

int ceilNumber(double x)
{
    int floor = x;
    // cout << "Number: " << x << endl;
    // cout << "Floor: " << floor << endl;
    if (floor < x)
    {
        // cout << "Ceil: " << (floor+1) << endl;
        return (floor + 1);
    }
    return floor;
}

// Base : parallel to y-axis
// height : parallel to x-axis

int solve(vector<string> &s)
{
    int n = s.size(), m = s[0].size();
    map<char, vector<int>> baseDown, baseUp;
    baseDown['g'] = baseDown['b'] = baseDown['r'] = vector<int>(m, 0);
    baseUp['g'] = baseUp['b'] = baseUp['r'] = vector<int>(m, n);

    map<char, int> hLeft, hRight;
    hLeft['r'] = hLeft['g'] = hLeft['b'] = m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            baseDown[s[i][j]][j] = max(baseDown[s[i][j]][j], i + 1);
            baseUp[s[i][j]][j] = min(baseUp[s[i][j]][j], i - 1);
            hRight[s[i][j]] = max(hRight[s[i][j]], j + 1);
            hLeft[s[i][j]] = min(hLeft[s[i][j]], j - 1);
        }
    }

    string chars = "rgb";

    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            double area = 0;
            for (int k = 0; k < 3; k++)
            {
                if (s[i][j] == chars[k])
                {
                    int a = chars[(k + 1) % 3];
                    int b = chars[(k + 2) % 3];

                    area = max(area, (max(baseDown[a][j] - i, i - baseUp[a][j]) * max(hRight[b] - j, j - hLeft[b])) / 2.0);

                    area = max(area, (max(baseDown[b][j] - i, i - baseUp[b][j]) * max(hRight[a] - j, j - hLeft[a])) / 2.0);
                }
            }
            ans = max(ans, area);
        }
    }
    return ceil(ans);
}

int32_t main()
{
    setupIO();
    double n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int ans = solve(s);
    cout << ans << endl;
    // cout << ceilNumber(n) << endl;
}