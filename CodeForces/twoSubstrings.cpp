//https://codeforces.com/problemset/problem/550/A
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin>>s;

    int n = s.length();

    bool B1 = false, A1 = false, B2 = false, A2 = false;
    int ind = 0;
    for(int i=0;i<n-1;i++){
        if(s[i]=='B' && s[i+1]=='A'){
            B1 = true;
            ind = i+2;
            break;
        }
    }
    if(B1){
        for(int i=ind;i<n-1;i++){
            if(s[i]=='A' && s[i+1]=='B'){
                A1 = true;
                break;
            }
        }
    }

    for(int i=0;i<n-1;i++){
        if(s[i]=='A' && s[i+1]=='B'){
            A2 = true;
            ind = i+2;
            break;
        }
    }

    if(A2){
        for(int i=ind;i<n-1;i++){
            if(s[i]=='B' && s[i+1]=='A'){
                B2 = true;
                break;
            }
        }
    }
    if((B1&&A1)||(A2 && B2))cout<<"YES\n";
    else cout<<"NO\n";



    return 0;
}