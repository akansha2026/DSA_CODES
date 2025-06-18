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

int32_t main()
{
    setupIO();
    string cookie;
    cin >> cookie;
    int i = 0;
    int n = cookie.size();
    map<string, string> mp;
    string key = "", value = "";
    bool isKey = true;
    while (i < n)
    {
        if(isKey){
            while(i < n && cookie[i] != '='){
                key.push_back(cookie[i]);
                i++;
            }
            i++;
            isKey = false;
        }
        if(!isKey){
            while(i < n && cookie[i] != ';'){
                value.push_back(cookie[i]);
                i++;
            }
            i++;
            isKey = true;
            mp[key] = value;
            key = "";
            value = "";
        }
    }

    for(auto &it:mp){
        cout << it.first << ": " << it.second << endl;
    }
}