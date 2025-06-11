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

bool bfs(int node, vector<int> &color, vector<bool> &vis, vector<vector<int>> &grid){
    vis[node] = true;
    queue<int> q;
    q.push(node);
    color[node] = 1;
    int c = 2;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int par = q.front();
            q.pop();
            for(auto &ch:grid[par]){
                if(!vis[ch]){
                    color[ch] = c;
                    q.push(ch);
                    vis[ch] = true;
                }
                else if(vis[ch] && color[ch] == color[par]) {
                    return false;
                }
            }
        }
        if(c == 2) c = 1;
        else c = 2;
    }
    return true;
}

bool dfs(int node, int c, vector<int> &color, vector<bool> &vis, vector<vector<int>> &grid){
    vis[node] = true;
    color[node] = c;

    if(c == 1) c= 2;
    else c = 1;

    for(auto &ch:grid[node]){
        if(!vis[ch]){
            if(!dfs(ch, c, color, vis, grid)) return false;
        }
        else if(color[ch] == color[node]) return false;
    }
    return true;
}

int32_t main() {
    setupIO();
    int n;
    cin >> n;
    vector<vector<int>> grid(n);
    for(int i=0; i<n; i++){
        int m;
        cin >> m;
        for(int j=0; j<m; j++){
            int x;
            cin >> x;
            grid[i].push_back(x);
        }
    }
    vector<bool> vis(n, false);
    vector<int> color(n);
    if(dfs(0, 1, color, vis, grid)) cout << "YES" << endl;
    else cout << "NO" << endl;
}