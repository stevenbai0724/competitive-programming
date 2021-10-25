//https://dmoj.ca/problem/dmopc19c5p4
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin>>n>>q;
    gp_hash_table<int, int>mp;
    int mx = 0;

    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    vector<int>psa(n+1);
    vector<int>vals, ind;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        psa[i] = arr[i] + psa[x];
        if(psa[i]>mx){
            mx = psa[i];
            vals.push_back(psa[i]);
            ind.push_back(i);
        }
    }
    while(q--){
        int x, y;
        cin>>x>>y;
        int cur = y-x;
        auto it = lower_bound(vals.begin(), vals.end(), cur);
        if(cur<=0 || it==vals.end()){
            cout<<-1<<"\n";
            continue;
        }
        cout<<ind[it-vals.begin()]<<"\n";
        
    }




    return 0;
}