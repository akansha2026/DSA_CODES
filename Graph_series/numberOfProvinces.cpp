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

void bfs(int node, vector<vector<int>> &adjList, vector<bool> &vis){
    queue<int> q;
    q.push(node);
    vis[node] = true;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(auto &x:adjList[top]){
            if(!vis[x]){
                vis[x] = true;
                q.push(x);
            }
        }
    }
}

int32_t main() {
    setupIO();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjacentMat(n, vector<int> (m)), adjacentList(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> adjacentMat[i][j];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i != j && adjacentMat[i][j] == 1){
                adjacentList[i].push_back(j);
            }
        }
    }

    vector<bool> vis(n, false);
    int ans = 0;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            bfs(i, adjacentList, vis);
            ans++;
        }
    }

    cout << "Ans is: " << ans << endl;
}