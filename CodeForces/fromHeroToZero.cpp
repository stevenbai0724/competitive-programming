#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    for(t; t>0;t--){
        int n, k, count;
        cin>>n>>k;
        count = 0;
        while(n>0){
            if(n%k!=0){
                count+= n%k;
                n-= (n%k);
                continue;
            }
            else{
                n/=k;
                count++;
            }
        }
        cout<<count<<"\n";
    }


    return 0;
}