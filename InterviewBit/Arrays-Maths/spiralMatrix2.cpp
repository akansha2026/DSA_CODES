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

vector<vector<int>> spiralMatrix(int n){
    int left = 0, right = n-1, top = 0, bottom = n-1;
    vector<vector<int>> ans(n, vector<int>(n));
    int cnt = 1;
    while(left <= right && top <= bottom){
        for(int i=left; i<=right; i++){
            ans[top][i] = cnt++;
        }
        top++;
        for(int i=top; i<=bottom; i++){
            ans[i][right] = cnt++;
        }
        right--;
        for(int i=right; i>=left; i--){
            ans[bottom][i] = cnt++;
        }
        bottom--;
        for(int i=bottom; i>=top; i--){
            ans[i][left] = cnt++;
        }
        left++;
    }
    return ans;
}

int32_t main() {
    setupIO();
    int n;
    cin >> n;
    vector<vector<int>> ans = spiralMatrix(n);
    for(auto &v:ans){
        for(auto &x:v) cout << x << " ";
        cout << endl;
    }
}