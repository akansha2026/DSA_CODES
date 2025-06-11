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

int32_t main() {
    setupIO();
    int n;
    cin >> n;
    vector,vector<int>> graph(n);
    for(int i=0; i<n; i++){
        int m;
        cin >> m;
        for(int j=0; j<m; j++){
            int x;
            cin >> x;
            graph[i].push_back(x);
        }
    }

    vector<int> ans;
    
}