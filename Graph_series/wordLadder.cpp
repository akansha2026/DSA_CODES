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

int bfs(string b, string e, vector<string> &w)
{   
    set<string> st;
    for(auto &s:w) st.insert(s);
    queue<string> q;
    set<string> vis;
    vis.insert(b);
    q.push(b);
    int level = 1;
    while (!q.empty())
    {
        string curr = q.front();
        q.pop();
        if (curr == e)
            return level;
        int m = curr.size();
        for (int i = 0; i < m; i++)
        {
            char orig = curr[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                curr[i] = ch;
                if (st.find(curr) != st.end() && vis.find(curr) == vis.end())
                {
                    vis.insert(curr);
                    q.push(curr);
                }
            }
            curr[i] = orig;
        }
        level++;
    }
    return 0;
}

int32_t main()
{
    setupIO();
    string beginWord, endWord;
    cin >> beginWord >> endWord;

    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    cout << bfs(beginWord, endWord, words) << endl;
}