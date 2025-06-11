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

string topoSortAlgo(map<int,vector<int>> &mp, map<int,int> &inDeg){
    queue<int> q;
    for(auto &it:inDeg){
        if(it.second == 0) q.push(it.first);
    }
    string ans = "";
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node + 'a');

        for(auto &ch:mp[node]){
            inDeg[ch]--;
            if(inDeg[ch] == 0) q.push(ch);
        }
    }
    return ans;
}

int32_t main() {
    setupIO();
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i=0; i<n; i++){
        cin >> words[i];
    }

    map<int,vector<int>> mp;
    map<int, int> inDeg;
    for(int i=1; i<n; i++){
        string s1 = words[i-1];
        string s2 = words[i];
        
        int j = 0, k = 0;
        while(j < s1.size() && k < s2.size()){
            if(s1[j] != s2[k]){
                mp[s1[j] - 'a'].push_back(s2[k] - 'a');
                inDeg[s2[k] - 'a']++;
                break;
            }
            j++;
            k++;
        }
    }
    
    for(auto &s:words){
        for(auto &ch:s){
            if(inDeg.find(ch-'a') == inDeg.end()){
                inDeg[ch - 'a'] = 0;
            }
        }
    }
    cout << topoSortAlgo(mp, inDeg) << endl;
}