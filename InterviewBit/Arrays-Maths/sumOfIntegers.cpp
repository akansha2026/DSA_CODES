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
vector<int> addArrays(vector<int> &A, vector<int> &B) {
    vector<int> ans;
    int carry = 0;
    int n = A.size(), m = B.size();
    
    int i=n-1, j = m-1;
    while(i>=0 && j>=0){
        int num = A[i]+B[j]+carry;
        carry = num/10;
        ans.push_back(num%10);
        i--;
        j--;
    }
    while(i >= 0){
        int num = A[i] + carry;
        carry = num / 10;
        ans.push_back(num%10);
        i--;
    }
    while(j >= 0){
        int num  = B[j] + carry;
        carry = num / 10;
        ans.push_back(num%10);
        j--;
    }
    if(carry) ans.push_back(carry);
    reverse(ans.begin(), ans.end());
    return ans;
}

int32_t main() {
    setupIO();
    int n, m;
    cin > n >> m;
    vector<int> A(n), B(m);
    for(int i=0; i<n; i++) cin >> A[i];
    for(int i=0; i<m; i++) cin >> B[i];

    vector<int> ans = addArrays(A, B);
    for(auto &x:ans) cout << x < " ";
    cout << endl;
}