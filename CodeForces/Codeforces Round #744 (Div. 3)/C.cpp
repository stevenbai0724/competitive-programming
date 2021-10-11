//https://codeforces.com/contest/1579/problem/C
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n, m, k;
        cin>>n>>m>>k;
        vector<vector<char>>arr(n+1, vector<char>(m+1));

        for(int i=1;i<=n;i++){
            string s; cin>>s;
            for(int j=1;j<=m;j++){
                arr[i][j] = s[j-1];
            }
        }
        vector<vector<bool>>good(n+1, vector<bool>(m+1));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr[i][j]=='*'){
                    pair<int, int>L = {i-1, j-1};
                    pair<int, int>R = {i-1, j+1};
                    int cntL = 0;
                    int cntR = 0;
                    int move = 0;
                    while(L.first>=1 && L.second>=1 && arr[L.first][L.second]=='*'){
                        cntL++;
                        L.first--;
                        L.second--;
                    }
                    while(R.first>=1 && R.second<=m && arr[R.first][R.second]=='*'){
                        cntR++;
                        R.first--;
                        R.second++;
                    }
                    move = min(cntR, cntL);
                    if(move>=k){
                        good[i][j] = true;
                        for(int k=1;k<=move;k++){
                            good[i-k][j-k] = true;
                            good[i-k][j+k] = true;
                        }
                    }
                }
            }
        }
        bool ans = true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(!good[i][j] && arr[i][j]=='*')ans = false;
            }
        }
        cout<<(ans ? "Yes" : "No")<<"\n";

    }


    return 0;
}