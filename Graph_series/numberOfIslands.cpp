#include <bits/stdc++.h>
using namespace std;

// setupIO
void setupIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// Using Grpah basics (we can do this using dfs also)
void bfs(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &vis)
{
    queue<pair<int, int>> q;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();

    vis[row][col] = true;
    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {1, -1, 0, 0};

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newR = r + dr[i];
            int newC = c + dc[i];
            if (newR >= 0 && newR < n && newC >= 0 && newC < m && !vis[newR][newC] && grid[newR][newC] == 1)
            {
                vis[newR][newC] = true;
                q.push({newR, newC});
            }
        }
    }
}

// COvert (row, col) to index
int index(int row, int col, int totalCol)
{
    return (row * totalCol + col);
}

// Now let's use DSU beacuse we can learn/revise that with the help of questions
class DSU
{
    // This is parent array
    vector<int> par, size;

public:
    DSU()
    {
        cout << "Initialise default constructor : " << endl;
    }

    DSU(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        par.resize(n * m);
        size.resize(n * m, 1);
        // Initially we'll assume that node itself parent
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int node = index(i, j, m);
                if (grid[i][j] == 1)
                    par[node] = node;
                else
                    par[node] = -1;
            }
        }
    }

    // Here we try to find that the topmost parent
    int find(int x)
    {
        if (par[x] == x)
            return x;

        return par[x] = find(par[x]);
    }

    // Join the nodes x and y according to thier parents info
    void join(int x, int y)
    {
        int parX = find(x);
        int parY = find(y);

        if (parX == parY)
            return;

        if (size[parX] > size[parY])
        {
            par[parY] = parX;
            size[parX] += size[parY];
        }
        else
        {
            par[parX] = parY;
            size[parY] += size[parX];
        }
    }

    // Main function corressponding to the problem
    int numOfIslands()
    {
        int ans = 0;
        int n = par.size();
        for (int i = 0; i < n; i++)
        {
            if (par[i] == i)
                ans++;
        }
        return ans;
    }
};

int32_t main()
{
    setupIO();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                bfs(i, j, grid, vis);
                ans++;
            }
        }
    }

    // Now doing this same problem using DSU
    DSU dsu(grid);

    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {1, -1, 0, 0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x = index(i, j, m);

            if (grid[i][j] == 1)
            {
                for (int k = 0; k < 4; k++)
                {
                    int newR = i + dr[k];
                    int newC = j + dc[k];
                    if (newR >= 0 && newR < n && newC >= 0 && newC < m && grid[newR][newC] == 1)
                    {
                        int y = index(newR, newC, m);
                        dsu.join(x, y);
                    }
                }
            }
        }
    }

    cout << "Ans using DSU is: " << dsu.numOfIslands() << endl;
    cout << "Ans is: " << ans << endl;
}