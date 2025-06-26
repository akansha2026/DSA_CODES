#include <bits/stdc++.h>
using namespace std;

/*
    In this, The bool array represent the true/false at 
    any index that if it is true means that 
    index number isprime otherwise not
*/
vector<bool> sieveOfEratothenes(int A){
    vector<bool> isPrime(A+1, true);
    isPrime[0] = isPrime[1] = false;
    int limit = (int)(sqrt(A));
    for(int i=2; i<=limit; i++){
        if(isPrime[i]){
            for(int j=2*i; j<=A; j+=i){
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

vector<int> primesum(int A) {
    vector<bool> isPrime(A+1, true);
    isPrime[0] = isPrime[1] = false;
    int limit = (int)(sqrt(A));
    for(int i=2; i<=limit; i++){
        if(isPrime[i]){
            for(int j=2*i; j<=A; j+=i){
                isPrime[j] = false;
            }
        }
    }

    cout << isPrime.max_size() << endl;

    vector<int> ans;
    for(int i=2; i<=A; i++){
        if(isPrime[i]) {
            ans.push_back(i);
        }
    }
    
    int i=0, j = ans.size()-1;
    while(i <= j){
        int sum = ans[i] + ans[j];
        cout << ans[i] << ", " << ans[j] << ", " << sum << endl;
        if(sum == A){
            return {ans[i], ans[j]};
        }
        else if(sum < A){
            i++;
        }
        else j--;
    }
    return {-1, -1};
}


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
    int n ;
    cin >> n;
    vector<int> ans = primesum(n);
    cout << ans[0] << ", " << ans[1] << endl;
}