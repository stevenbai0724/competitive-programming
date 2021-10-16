//https://dmoj.ca/problem/cactus
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k;
    cin>>n>>m>>k;

    vector<pair<double, double>>armor(k+1);
    vector<int>arr(2e5+2);
    vector<int>psa(2e5+2);

    for(int i=1;i<=k;i++){
        double a, b;
        cin>>a>>b;
        b = 100.0 - b;
        b/=100.0;
        armor[i] = {a,b};

    }

    for(int i=1;i<=m;i++){
        int x, y, z;
        cin>>x>>y>>z;

        arr[x]+=z;
        arr[x+y]-=z;

    }
    int sum = 0;
    for(int i=0;i<=2e5;i++){
        sum += arr[i];
        psa[i] = sum;
    }

    double ans = n;
    for(int i=0;i<=2e5;i++){
        double val = psa[i];
        double mn = 1e18;

        if(val==0)continue;

        for(int j=1;j<=k;j++){
            mn = min(mn, (val-armor[j].first)*armor[j].second);
        }

        mn = max(mn, (double)0);

        ans -= mn;

    }
    if(ans<0) cout<<"Act Like A Cactus.\n";

    else cout<<setprecision(2)<<fixed<<ans<<"\n";




    return 0;
}