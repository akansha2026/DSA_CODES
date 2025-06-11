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


// Solve the problem using bfs
/*
    So first clear the concept of this problem that is if any 'O' is connected to boundary then there group which is O's group can't be replace to 'X' so that's why we have start the bfs or dfs from the boundaries 'O' and move to thier group and remaining  not visisted group can replaced
*/

void bfs(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vis(n, vector<bool> (m, false));
    queue<pair<int,int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if((i == 0 || i == n-1 || j == 0 || j == m-1) && grid[i][j] == 'O'){
                q.push({i,j});
                vis[i][j] = true;
            }
            else if(grid[i][j] == 'X') vis[i][j] = true;
        }
    }

    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {-1, 1, 0, 0};
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int  newR = r + dr[i];
                int  newC = c + dc[i];
                if(newR >= 0 && newR < n && newC >= 0 && newC < m && !vis[newR][newC] && grid[newR][newC] == 'O'){
                    vis[newR][newC] = true;
                    q.push({newR, newC});
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 'O'){
                vis[i][j] = true;
                grid[i][j] = 'X';
            }
        }
    }
}

int32_t main() {
    setupIO();
    int n, m;
    cin >> n >>m;
    vector<vector<char>> grid(n, vector<char>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> grid[i][j];
    }

    bfs(grid);
    for(auto &v:grid){
        for(auto &x:v) cout << x << " ";
        cout << endl;
    }
}