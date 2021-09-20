//
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    string s; cin>>s;
    int cnt1 = 0, cnt2 = 0;


    for(int i=0;i<n;i++){
        if(s[i]=='D')cnt1++;
        else cnt2++;
    }

    if(cnt1>cnt2)cout<<"Danik\n";
    else if(cnt1<cnt2)cout<<"Anton\n";
    else cout<<"Friendship\n";


    return 0;
}