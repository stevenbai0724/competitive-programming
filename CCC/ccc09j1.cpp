//https://dmoj.ca/problem/ccc09j1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int ans = 91;

    for(int i=1;i<=3;i++){
        int x; cin>>x;

        if(i&1){
            ans += x;
        }
        else ans += x+x+x;
    }
    cout<<"The 1-3-sum is "<<ans<<"\n";




    return 0;
}