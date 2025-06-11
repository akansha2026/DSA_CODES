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

// Let's slove the flood fill problem using bfs
void bfs(int sr, int sc, int color, vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {-1, 1, 0, 0};

    int initialColor = grid[sr][sc];
    queue<pair<int,int>> q;
    q.push({sr,sc});
    grid[sr][sc] = color;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vis[sr][sc] = true;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int newR = r + dr[i];
            int newC = c + dc[i];

            if(newR >= 0 && newR < n && newC >= 0 && newC < m && !vis[newR][newC] && grid[newR][newC] == initialColor){
                q.push({newR, newC});
                vis[newR][newC] = true;
                grid[newR][newC] = color;
            }
        }
    }
}

int32_t main() {
    setupIO();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> grid[i][j];
    }
    int sr, sc, color;
    cin >> sr >> sc >> color;
    
    // Call the function
    bfs(sr, sc, color, grid);
    
    // Now the final result
    for(auto &v:grid){
        for(auto &x:v) cout << x << " ";
        cout << endl;
    }
}