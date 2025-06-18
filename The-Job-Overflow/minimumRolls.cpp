#include <bits/stdc++.h>
using namespace std;

void setupIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

// DFS + backtracking to count number of valid paths
int numOfPaths(int r, int c, int destR, int destC, vector<vector<bool>> &vis, vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    if (r < 0 || c < 0 || r >= n || c >= m || vis[r][c] || grid[r][c] == 0)
        return 0;

    if (r == destR && c == destC)
        return 1;

    vis[r][c] = true;

    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {-1, 1, 0, 0};
    int totalPaths = 0;

    for (int i = 0; i < 4; i++) {
        int newR = r + dr[i];
        int newC = c + dc[i];
        totalPaths += numOfPaths(newR, newC, destR, destC, vis, grid);
    }

    vis[r][c] = false;
    return totalPaths;
}

int32_t main() {
    setupIO();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    int srcR, srcC, destR, destC;
    cin >> srcR >> srcC >> destR >> destC;

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int ans = numOfPaths(srcR, srcC, destR, destC, vis, grid);
    cout << ans << endl;

    return 0;
}
