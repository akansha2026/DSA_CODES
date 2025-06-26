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

bool isMatching(int i, int j, string &s1, string &s2){
    int n = s1.size(), m = s2.size();

    if(i == n && j == m) return true;
    if(i == n || j == m) return false;

    if(s1[i] == s2[j] || s1[i] == '?' ){
        return isMatching(i+1, j+1, s1, s2);
    }

    if(s1[i] == '*') return isMatching(i-1, j, s1, s2) || isMatching(i, j-1, s1, s2);

    return false;
}

int32_t main() {
    setupIO();
    string s1, s2;
    cin >> s1  >> s2;
    bool ans = isMatching(0, 0, s1, s2);
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}