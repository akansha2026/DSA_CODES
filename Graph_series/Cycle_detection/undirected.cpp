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

// Detect a cycle using dfs
bool bfs(int src, vector<bool> &vis, vector<vector<int>> &grid){
    vis[src] = true;
    // {src, par}
    queue<pair<int,int>> q;
    q.push({src, -1});
    while(!q.empty()){
        int par = q.front().second;
        int node = q.front().first;
        q.pop();

        for(auto &x:grid[node]){
            if(!vis[x]){
                q.push({x, node});
                vis[x] = true;
            }
            else {
                if(vis[x] && x != par) return true;
            }
        }
    }
    return false;
}

// Detecting cycle using DFS
bool dfs(int src, int par, vector<bool> &vis, vector<vector<int>> &grid){
    vis[src] = true;
    for(auto &ch:grid[src]){
        if(!vis[ch]){
            vis[ch] = true;
            bool ans = dfs(ch, src, vis, grid);
            if(ans) return true;
        }
        else if(ch != par) return true;
    }
    return false;
}

int32_t main() {
    setupIO();
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjList(n);
    for(int i=0; i<e; i++){
        int u , v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> vis(n, false);

    if(dfs(0, -1, vis, adjList)) cout << "YES" << endl;
    else cout << "NO" << endl;
}