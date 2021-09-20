//https://codeforces.com/contest/1474/problem/0
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        vector<int>arr(s.length());
        string ans = "";
        ans+="1";
        arr[0] = (int)(s[0])+1;
        for(int i =1;i<s.length();i++){
            int cur = (int)s[i];
            if((1+cur)!=arr[i-1]){
                arr[i] = cur+1;
                ans+="1";
            }
            else{
                arr[i] = (int)s[i];
                ans+="0";
            }
        }
        cout<<ans<<"\n";

    }
    
    return 0;
}