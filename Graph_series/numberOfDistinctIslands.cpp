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

pair<int,int> findRowAndCol(int r1, int c1, int r2, int c2){
    if(r1 > r2){
        if(c1 > c2){
            return {(r1 - r2), (c1 - c2)};
        }
        return {(r1 - r2), (c2 - c1)};
    }
    else {
        if(c1 > c2){
            return {(r1 - r2), (c1 - c2)};
        }
        return {(r1 - r2), (c2 - c1)};
    }
}

void bfs(int row, int col, vector<pair<int,int>> &v, vector<vector<bool>> &vis, vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>> q;
    q.push({row, col});
    vis[row][col] = true;

    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {-1, 1, 0, 0};
    v.push_back({0, 0});
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int  newR = r + dr[i];
                int  newC = c + dc[i];
                if(newR >= 0 && newR < n && newC >= 0 && newC < m && !vis[newR][newC] && grid[newR][newC] == 1){
                    vis[newR][newC] = true;
                    q.push({newR, newC});
                    v.push_back(findRowAndCol(row, col, newR, newC));
                }
            }
        }
    }
    
}

int32_t main() {
    setupIO();
    int n, m;
    cin >> n >>m;
    vector<vector<int>> grid(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> grid[i][j];
    }

    set<vector<pair<int,int>>> st;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                vector<pair<int,int>> v;
                bfs(i, j, v, vis, grid);
                st.insert(v);
            }
        }
    }

    cout << "Number of distinct islands is(are): " << st.size() << endl;
}