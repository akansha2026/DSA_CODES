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

// DFS
void dfs(int node, vector<bool> &vis, vector<bool> &pathVis, stack<int> &st, vector<vector<pair<int,int>>> &grid){
    vis[node] = true;
    pathVis[node] = true;

    for(auto &ch:grid[node]){
        if(!vis[ch.first]){
            dfs(ch.first, vis, pathVis, st, grid);
        }
    }
    pathVis[node]  = false;
    st.push(node);
}

int32_t main() {
    setupIO();
    int n, e, src;
    cin >> n >> e >> src;
    vector<vector<pair<int,int>>> grid(n);
    for(int i=0; i<e; i++){
        int u , v, w;
        cin >> u >> v >> w;
        grid[u].push_back({v, w});
    }

    vector<int> dist(n, 1e9);
    vector<bool> vis(n, false), pathVis(n, false);
    stack<int> st;
    for(int i=0; i<=src; i++){
        if(!vis[i]) dfs(i, vis, pathVis, st, grid);
    }

    dist[src] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto &ch:grid[node]){
            if(dist[ch.first] > dist[node] + ch.second){
                dist[ch.first] = dist[node] + ch.second;
            }
        }
    }

    for(auto &x:dist) {
        if(x == 1e9) cout << -1 << " ";
        else cout << x << " ";
    }
    cout << endl;
}