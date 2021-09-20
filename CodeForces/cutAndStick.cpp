//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, q;
    cin>>n>>q;

    vector<int>arr(n+1);
    vector<vector<int>>ind(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        ind[arr[i]].push_back(i);
        
    }
    for(int i=1;i<=n;i++){
        ind[i].push_back(n+1);
    }

    while(q--){
        int l,r;
        cin>>l>>r;

        int len = r-l+1;
        double mx = ceil(len/2.0);

        int mxCnt = 0;

        for(int t = 0; t<50; t++){
            int idx = rng()%len + l;
            int num = arr[idx];

            auto it1 = upper_bound(ind[num].begin(), ind[num].end(), r);
            auto it2 = lower_bound(ind[num].begin(), ind[num].end(), l);

            int cnt = it1 - it2;    

            mxCnt = max(mxCnt, cnt);
        }
        if(mxCnt<=mx){
            cout<<"1\n";
            continue;
        }
        cout<<len - (len-mxCnt)*2<<"\n";

    }
    return 0;
}