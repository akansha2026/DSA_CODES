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
    int a, b, c;
    cin >> a >> b >> c;
    a = a % b;
    int ans = (a + c) % b;
    if(ans == 0) cout << (b - 1) << endl;
    else cout << (ans - 1) << endl;
}