//https://codeforces.com/problemset/problem/1311/C
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n, m;
        cin>>n>>m;
        string s; cin>>s;

        vector<int>freq(26);
        vector<vector<int>>arr(n+1, vector<int>(26));

        for(int i=0;i<n;i++){
            freq[s[i]-97]++;
            arr[i+1] = arr[i];
            arr[i+1][s[i]-97]++;

        }
        while(m--){
            int x; cin>>x;
            for(int i=0;i<26;i++){
                freq[i]+=arr[x][i];
            }
        }
        for(auto x: freq)cout<<x<<" ";
        cout<<"\n";
    }


    return 0;
}