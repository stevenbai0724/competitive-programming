//https://codeforces.com/problemset/problem/1324/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        vector<int>arr(s.length()+2,0);
        bool L = true;
        bool R = true;
        int count  =0;
        int ans = 0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='R'){
                L = false;
                arr[i+1] = 1;
            }
            else R = false;
        }
        if(L){
            cout<<s.length()+1<<"\n";
            continue;
        }
        if(R){
            cout<<1<<"\n";
            continue;
        }
        for(int i=1;i<=s.length();i++){
            if(arr[i]==0)count++;
            else{
                ans = max(count, ans);
                count = 0;
            }
            if(i==s.length()){
                ans = max(count, ans);
            }
        }
        cout<<ans+1<<"\n";




    }


    return 0;
}