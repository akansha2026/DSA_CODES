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

// Let's detect the cycle using dfs
/*
So basically what is the concept for checking that is there any cycle exist in directed graph or not . We have to keep a pathVisited array also by which we can understand that in we are coming on the node that we already visited in the same path if that node visited and not lie in the same path it doesn't mean that cycle exist
*/
bool isCycleDFS(int node, int par, vector<bool> &pathVis, vector<bool> &vis, vector<vector<int>> &grid){
    vis[node] = true;
    pathVis[node] = true;
    for(auto &ch:grid[node]){
        if(!vis[ch]){
            if(isCycleDFS(ch, node, pathVis, vis, grid)) return true;
        }
        else if(pathVis[ch]) return true;
    }
    pathVis[node] = false;
    return false;
}

// Let's use the bfs wya for detecting the cycle in direct graph

bool bfs(int node, vector<bool> &vis, vector<vector<int>> &grid){
    vis[node] = true;

    queue<pair<int,int>> q;
    q.push({node, -1});

    while(!q.empty()){
        int x = q.front().first;
        int par = q.front().second;
        q.pop();

        for(auto &ch:grid[node]){
            if(!vis[ch]){
                vis[ch] = true;
                q.push({ch, node});
            }
            else if(ch != par) return true;
        }
    }
    return false;
}

int32_t main() {
    setupIO();
    int n, e;
    cin >> n >> e;
    vector<vector<int>> grid(n);
    for(int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;
        grid[u].push_back(v);
    }

    vector<bool> vis(n, false), pathVis(n, false);
    bool isExist = false;
    for(int i=0; i<n; i++){
        if(!vis[i] && bfs(i, vis, grid)) {
            cout << "Cycle exist!" << endl;
            isExist = true;
            break;
        }
    }
    if(!isExist) cout << "Cycle not exist!" << endl;
}