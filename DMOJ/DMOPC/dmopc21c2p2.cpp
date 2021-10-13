//https://dmoj.ca/problem/dmopc21c2p2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, t;
    cin>>n>>t;
    map<int, int>mp, mp2; //ith position has the number mp[i] in it
                            //number i is in the position mp2[i]
    for(int i=1;i<=n;i++){
        mp[i] = i;
        mp2[i] = i;
    }

    while(t--){
        char c; cin>>c;
        if(c=='B'){
            int x, y;
            cin>>x>>y;

            int ind1 = mp2[x];
            int ind2 = mp2[y];

            int temp = mp[ind1];
            mp[ind1] = mp[ind2];
            mp[ind2] = temp;

            mp2[y] = ind1;
            mp2[x] = ind2;

        }
        if(c=='E'){
            int x, y;
            cin>>x>>y;

            int temp = mp[x];
            mp[x] = mp[y];
            mp[y] = temp;

            mp2[mp[x]] = x;
            mp2[mp[y]] = y;

        }
        if(c=='Q'){
            vector<int>ans(n+1);
            for(int i=1;i<=n;i++){
                int x; cin>>x;
                ans[mp[i]] = x;
            }
            for(int i=1;i<=n;i++){
                cout<<ans[i];
                if(i<n)cout<<" ";
            }
            cout<<"\n";
        }
    }




    return 0;
}