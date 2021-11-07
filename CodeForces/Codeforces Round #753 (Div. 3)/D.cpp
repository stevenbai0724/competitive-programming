//https://codeforces.com/contest/1607/problem/D
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
        int n; cin>>n;
        vector<int>arr(n+1);

        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

        vector<pair<int, char>>use;

        string s; cin>>s;
        int L = 1;
        int R = n;
        for(int i=0;i<s.length();i++){
            if(s[i]=='B'){
                if(arr[i+1]<1){
                    cout<<"NO\n";
                    goto nxt;
                }
                int val = min(arr[i+1], n);
                use.push_back({val, 'B'});
            }
            else{
                if(arr[i+1]>n){
                    cout<<"NO\n";
                    goto nxt;
                }
                int val = max(arr[i+1], (int)1);
                use.push_back({n-val+1, 'R'});
            }
        }
        sort(use.begin(), use.end());


        for(auto p: use){
            int tier = p.first;
            char type = p.second;
            if(type=='B'){
                if(tier>=L){
                    L++;
                }
                else{
                    cout<<"NO\n";
                    goto nxt;
                }
            }
            else{
                if(n-tier+1<=R){
                    R--;
                }
                else{
                    cout<<"NO\n";
                    goto nxt;
                }
            }

        }
        cout<<"YES\n";

    
        nxt:;


    }



    return 0;
}