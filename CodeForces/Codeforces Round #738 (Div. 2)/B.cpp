//https://codeforces.com/contest/1559/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        vector<pair<int, int>>arr;
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                int j = i;
                while(j<n-1 && s[j+1] == '?')j++;
                arr.push_back({i,j});
                i = j;
            }
        }
        if(s[0]=='?'){
            char cur = ' ';
            if(s[arr[0].second+1]=='R')cur = 'B';
            else cur = 'R';
            for(int i=arr[0].second;i>=0;i--){
                s[i] = cur;
                if(cur=='R')cur = 'B';
                else cur  = 'R';
            }
        }
        for(auto p : arr){
            if(p.first==0)continue;
            char cur = ' ';
            if(s[p.first-1]=='R')cur = 'B';
            else cur = 'R';

            for(int i=p.first;i<=p.second;i++){
                s[i] = cur;
                if(cur=='R')cur = 'B';
                else cur  = 'R';
            }
        }
        cout<<s<<"\n";
    }


    return 0;
}