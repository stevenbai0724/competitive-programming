//https://codeforces.com/contest/1582/problem/C
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

bool good(string str){
    int len = str.length();
    bool pal = true;
    for(int i=0;i<=(len-1)/2;i++){
        if(str[i]!=str[len-i-1])pal = false;
    }
    return pal;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        if(good(s)){
            cout<<0<<"\n";
            continue;
        }
        int ans = 1e18;
        for(int i=0;i<26;i++){
            char c = i+97;
            int L = 0;
            int R = n-1;
            bool good = true;
            int cnt = 0;

            while(true){
                if(s[L]==s[R]){
                    L++;
                    R--;
                }
                else{
                    if(s[L]==c){
                        L++;
                        cnt++;
                    }
                    else if(s[R]==c){
                        R--;
                        cnt++;
                    }
                    else{
                        good = false;
                        break;
                    }
                }
                if(L>R)break;
            }
            if(good)ans = min(ans, cnt);
        }
        cout<<(ans==1e18 ? -1 :ans)<<"\n";
    }
    return 0;
}