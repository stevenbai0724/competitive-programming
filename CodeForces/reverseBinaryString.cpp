//
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;

        string check1 = '1' + s + '0';
        string check2 = '0' + s + '1';
        int cnt1 = 0, cnt2 = 0;

        for(int i=0;i<n+1;i++){
            if(check1[i]==check1[i+1])cnt1++;
            if(check2[i]==check2[i+1])cnt2++;
        }

        cout<<min(cnt1, cnt2)/2<<"\n";


    }


    return 0;
}