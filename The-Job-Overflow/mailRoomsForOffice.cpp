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

void bfs(int node, vector<bool> &vis, vector<vector<int>> &grid){
    vis[node] = true;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(auto &ch:grid[top]){
            if(!vis[ch]) vis[ch] = true;
        }
    }
}
int32_t main() {
    setupIO();

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(m);
    for(int i=0; i<n; i++){
        int u, v;
        cin >> u >> v;
        grid[u].push_back(v);
        grid[v].push_back(u);
    }

    vector<bool> vis(n, false);
    int ans = 0;

    for(int i=0; i<n; i++){
        if(!vis[i]){
            ans++;
            bfs(i, vis, grid);
        }
    }
    cout << ans << endl;
}