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

map<int, int> primeFactors(int n)
{
    int i = 2;
    map<int, int> mp;
    while (n > 1)
    {
        if (n % i == 0)
        {
            mp[i]++;
            n /= i;
        }
        else
            i++;
    }
    return mp;
}

int hcf(int a, int b)
{
    if (b % a == 0)
        return a;
    return hcf(b % a, a);
}

// hcf(9, 6)

int32_t main()
{
    setupIO();
    int n;
    cin >> n;

    map<int, int> mp = primeFactors(n);
    for (auto &it : mp)
    {
        int sz = it.second;
        while (sz--)
            cout << it.first << " ";
    }
    cout << endl;
    double phi = (1 + sqrt(5))/2;
    int ans = (int)((pow(phi, n) - pow((1 - phi), n))/ sqrt(5));
    cout << ans << endl;
}