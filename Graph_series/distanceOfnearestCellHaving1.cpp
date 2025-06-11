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

void bfs(vector<vector<int>> &grid, vector<vector<int>> &dist){
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int,int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i=0;i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1){
                vis[i][j] = true;
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    int level = 1;
    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {-1, 1, 0, 0};
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int newR = r + dr[i];
                int newC = c + dc[i];
                if(newR >= 0 && newR < n && newC >= 0 && newC < m && !vis[newR][newC]){
                    dist[newR][newC] = level;
                    vis[newR][newC] = true;
                    q.push({newR, newC});
                }
            }
        }
        level++;
    }
}

int32_t main() {
    setupIO();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >>  grid[i][j];
        }
    }
    
    vector<vector<int>> dist(n, vector<int>(m));
    // Call the function
    bfs(grid, dist);

    // Now print the result
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cout << dist[i][j] << " ";
        cout << endl;
    }
}