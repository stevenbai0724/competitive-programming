//
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.length();

        vector<int>freq(150);
        bool found = false;
        for(auto c: s){
            freq[(int)c]++;
            if(freq[(int)c] >1)found = true;
        }
        if(found || freq[(int)('a')] == 0){
            cout<<"NO\n";
            continue;
        }

        int l, r;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                l = i;
                r = i;
            }
        }
        int cur = 'b';
        while(true){
            if(abs(l-r)+1 ==n){
                break;  
            }
            if(s[l-1]==cur){
                l--;
                cur++;
            }
            else if(s[r+1]==cur){
                r++;
                cur++;
            }

            else{
                cout<<"NO\n";
                goto nxt;
            }
            

        }
        cout<<"YES\n";
        nxt:;

    }

    return 0;
}