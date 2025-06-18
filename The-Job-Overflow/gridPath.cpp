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

bool isPathExist(pair<int, int> S, pair<int,int> E, vector<vector<bool>> &vis, vector<vector<char>> &grid){
    queue<pair<int,int>> q;
    q.push(S);
    vis[S.first][S.second] = true;
    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {-1, 1, 0, 0};
    int n = grid.size();
    int m = grid[0].size();
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        if(r == E.first && c == E.second) return true;
        q.pop();
        for(int i=0; i<4; i++){
            int newR = r + dr[i];
            int newC = c + dc[i];
            if(newR >= 0 && newR < n && newC >= 0 && newC < m && !vis[newR][newC] && grid[newR][newC] != '#'){
                vis[newR][newC] = true;
                q.push({newR, newC});
            }
        }
    }
    return false;
}

int32_t main() {
    setupIO();
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    pair<int,int> start, end;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'S'){
                start = {i, j};
            }
            if(grid[i][j] == 'E') end = {i, j};
        }
    }
    vector<vector<bool>> vis(n, vector<bool> (m, false));
    if(isPathExist(start, end, vis, grid)) cout << "YES" << endl;
    else cout << "NO" << endl;
}