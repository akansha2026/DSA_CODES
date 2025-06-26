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

int minMoves(int target){
    //  Firtsly we have to move forward till
    // then if we dont find the target limit 
    int sum = 0;
    int steps = 0;
    while(sum <= A){
        steps++;
        sum += i;
    }
    // Now we agin move forward but 
    // the condn is when the difference is 
    // even we will stop
    while((sum - A) % 2 != 0){
        steps++;
        sum +=m i;
    }
    return steps;
}

int32_t main() {
    setupIO();
    
}