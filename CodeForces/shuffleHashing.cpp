//https://codeforces.com/problemset/problem/1278/A
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int t; cin>>t;
    while(t--){
        string s, t;
        cin>>s>>t;
        vector<int>arr(124);
        vector<int>freq(124);
        int n = s.length();
        int m = t.length();
        bool found = false;
        for(auto c: s){
            arr[(int)c]++;
        }
        for(int i=0;i<n && i<m;i++){
            freq[(int)t[i]]++;
        }
        if(arr==freq)found = true;
        for(int i=0;i<m-n;i++){
            freq[(int)t[i]]--;
            freq[(int)t[i+n]]++;
            if(arr==freq){
                found =true; 
                break;
            }
        }

        if(found)cout<<"YES\n";
        else cout<<"NO\n";
    }
    
   
    return 0;

}