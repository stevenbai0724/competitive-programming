//https://dmoj.ca/problem/coci19c3p2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define double long double
#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin>>s;
    s = " " + s;

    int n = s.length()-1;
    int q; cin>>q;

    vector<pair<int, int>>words(q+1);

    for(int i=1;i<=q;i++){
        cin>>words[i].first>>words[i].second;
    }

    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    
    int L = -1;
    int R = n;

    while(L + 1 < R){
        int m = (L+R)/2;
        string cur = s;

        for(int i=1;i<=m;i++){
            cur[arr[i]] = '*';
        }
        vector<vector<int>>pfx(27, vector<int>(n+1));
        bool good = true;

        for(int i=0;i<26;i++){
            for(int j=1;j<=n;j++){
                pfx[i][j] = pfx[i][j-1];
                if(cur[j]-'a' == i)pfx[i][j]++;
            }
        }

        for(int i=1;i<=q;i++){
            int x = words[i].first;
            int y = words[i].second;

            for(int j=0;j<26;j++){
                int cnt = pfx[j][y] - pfx[j][x-1];
                if(cnt > 1)good = false;
            }
        }

        if(good)R = m;
        else L = m;
    }
    cout<<R<<"\n";





    return 0;
}