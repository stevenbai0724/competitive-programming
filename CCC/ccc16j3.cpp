//https://dmoj.ca/problem/ccc16j3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin>>s;

    int n = s.length();
    int ans = 1;
    for(int i=0;i<n;i++){ 
        int L = i;
        int R = i;
        while(L>0 && R<n-1 && s[L-1]==s[R+1]){
            R++;
            L--;
        }

        ans = max(ans, R-L+1);

    }
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1])continue;
        int L = i;
        int R = i+1;
        while(L>0 && R<n-1 && s[L-1]==s[R+1]){
            R++;
            L--;
        }
        ans = max(ans, R-L+1);
    }
    cout<<ans<<"\n";



    return 0;
}