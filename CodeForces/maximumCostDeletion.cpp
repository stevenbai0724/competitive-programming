//
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n, a, b;
        cin>>n>>a>>b;

        int ans = n*a;

        string s; cin>>s;

        if(b>=0)ans+=(n*b);

        else{
            int cnt1 = 0;
            int cnt0 = 0;

            for(int i=0;i<n;i++){
                if(s[i]=='1'){
                    int j = i;
                    while(j<n-1 && s[j+1]=='1')j++;
                    cnt1++;
                    i = j;
                }
                else{
                    int j = i;
                    while(j<n-1 && s[j+1]=='0')j++;
                    cnt0++;
                    i = j;
                }
            }
            ans+=(b*min(cnt1+1, cnt0+1));
        }
        cout<<ans<<"\n";



    }


    return 0;
}