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
vector<vector<int>> matrixMultiplication(vector<vector<int>> &a, vector<vector<int>> &b){
    int n1 = a.size();
    int m1 = a[0].size();
    int n2 = b.size();
    int m2 = b[0].size();
    const int MOD = 1e9 + 7;

    if(m1 != n2) return {{}};
    vector<vector<int>> ans;

    for(int i=0; i<n1; i++){
        vector<int> temp;
        for(int j=0; j<m2; j++){
            int val = 0;
            for(int k=0; k<m1; k++){
               val = (val % MOD + (1LL * (a[i][k] % MOD) * (b[k][j] % MOD))%MOD) % MOD;
            }
            temp.push_back(val);
        }
        ans.push_back(temp);
    }
    return ans;
}

int nthFib(int n){
    n--;
    vector<vector<int>> x = {{1, 1},{1, 0}};
    vector<vector<int>> ans = {{1, 0},{0, 1}};
    while(n > 0){
        if(n % 2 != 0){
            ans = matrixMultiplication(ans, x);
        }
        x = matrixMultiplication(x, x);
        n /= 2;
    }
    vector<vector<int>> initialVal = {{1}, {0}};
    ans = matrixMultiplication(ans, initialVal);
    return ans[0][0];
}

int32_t main() {
    setupIO();
    int n;
    cin >> n;
    cout << nthFib(n) << endl;
    cout << (-5 % 10) << endl;
}