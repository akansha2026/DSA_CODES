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

void setZero(vector<vector<int>> &mat){
    int n = mat.size(), m = mat[0].size();

    vector<int> row(n, 0), col(m, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i=0; i<n; i++){
        if(row[i]){
            for(int j=0; j<m; j++) mat[i][j] = 0;
        }
    }
    for(int j=0; j<m; j++){
        if(col[j]){
            for(int i=0; i<n; i++) mat[i][j] = 0;
        }
    }
}

int32_t main() {
    setupIO();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int> (m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> mat[i][j];
    }

    setZero(mat);
    for(auto &v:mat){
        for(auto &x:v) cout << x <<  " ";
        cout << endl;
    }
}