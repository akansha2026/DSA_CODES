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

int hammingDistance(const vector<int> &A)
{
    int n = A.size();
    const int MOD = 1e7;
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        int numOfSetBit = 0;
        for (int j = 0; j < n; j++)
        {
            if (((A[j] >> i) & 1) != 0)
                numOfSetBit++;
        }
        int numOfUnsetBit = n - numOfSetBit;
        ans = (ans % MOD + (numOfSetBit % MOD * numOfUnsetBit % MOD) % MOD) % MOD;
    }
    return (ans * 2) % MOD;
}

vector<string> fizzBuzz(int A) {
    vector<string> ans;
    int i=1;
    while(i <= A){
        if((i % 3 == 0) && (i % 5 == 0)) ans.push_back("FizzBuzz");
        else if(i % 3 == 0) ans.push_back("Fizz");
        else if(i % 5 == 0) ans.push_back("Buzz");
        else ans.push_back(to_string(i));
        i++;
    }
    return ans;
}


int32_t main()
{
    setupIO();
    int n;
    cin >> n;
    // vector<int> nums(n);
    // for (int i = 0; i < n; i++)
    //     cin >> nums[i];
    // int ans = hammingDistance(nums);
    // cout << ans << endl;

    vector<string> ans = fizzBuzz(n);
    for(auto &s:ans) cout << s << endl;
}