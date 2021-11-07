//https://codeforces.com/contest/1607/problem/A
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        string s, t;
        cin>>s>>t;
        vector<int>pos(26);

        for(int i=0;i<26;i++){
            char c = s[i];
            pos[c-97] = i;
        }
        int cnt = 0;
        for(int i=0;i<t.length()-1;i++){
            cnt += abs(pos[t[i]-97]-pos[t[i+1]-97]);
        }

        cout<<cnt<<"\n";


    }


    return 0;
}