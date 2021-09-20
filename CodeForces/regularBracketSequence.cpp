//https://codeforces.com/problemset/problem/1469/A
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool comp(int a, int b){
    return a>b;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    

    int t; cin>>t;

    while(t--){
        
        string s; cin>>s;
        int n = s.length();

        int cnt = 0;


        for(int i=0;i<n;i++){
            if(s[i]=='?')cnt++;
        }
        if(cnt%2==1){
            cout<<"NO\n";
            continue;
        }
        int left = cnt;
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                if(left>cnt/2)s[i]='(';
                else s[i] = ')';
                left--;
            }
        }
        int check = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')check++;
            else check--;

            if(check<0){
                cout<<"NO\n";
                goto nxt;
            }

        }
        cout<<"YES\n";
        nxt:;






    }


    return 0;
}