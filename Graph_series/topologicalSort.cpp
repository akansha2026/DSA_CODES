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

// DFS algorithm
/*
    the point is that we find one thing very important that if there is any cycle than we can't make topological sort. So that's why we are pushing the element after check that there is no cycle in that component
*/
void dfs(int node, vector<bool> &vis, stack<int> &st, vector<vector<int>> &grid){
    vis[node] = true;
    for(auto &ch:grid[node]){
        if(!vis[ch]) dfs(ch, vis, st, grid);
    }
    st.push(node);
}

vector<int> topoSort(vector<vector<int>> &grid){
    int n = grid.size();
    vector<bool> vis(n, false);
    vector<int> ans;
    stack<int> st;

    for(int i=0; i<n; i++){
        if(!vis[i]) dfs(i, vis, st, grid);
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

// BFS
/*
    In this we are starting with that node that have indegree 0
*/

vector<int> bfs(vector<vector<int>> &grid){
    int n = grid.size();
    vector<int> inDeg(n, 0);
    for(auto &v:grid){
        for(auto &x:v){
            inDeg[x]++;
        }
    }
    queue<int> q;
    for(int i=0; i<n; i++){
        if(inDeg[i] == 0) q.push(i);
    }

    vector<int> temp;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        temp.push_back(node);
        for(auto &ch:grid[node]){
            inDeg[ch]--;
            if(inDeg[ch] == 0){
                q.push(ch);
            }
        }
    }
    return temp;
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

    vector<int> ans = bfs(grid);
    for(auto &x:ans) cout << x << " ";
    cout << endl;
}