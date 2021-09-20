//https://codeforces.com/problemset/problem/271/A
//
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    for(int i=n+1;i<=10000;i++){
        string s = to_string(i);
        vector<int>freq(10);
        bool good = true;
        for(auto c: s){
            freq[c-48]++;
            if(freq[c-48]>1)good = false;
        }
        if(good){
            cout<<i<<"\n";
            return 0;
        }
    }

    return 0;
}