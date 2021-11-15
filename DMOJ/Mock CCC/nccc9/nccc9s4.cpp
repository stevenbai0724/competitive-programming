//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long


struct edge{
    int l, r, id;
};
bool comp(edge a, edge b){
    if(a.l<b.l)return true;
    if(a.l>b.l)return false;
    else {
        return a.r<b.r;
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin>>n>>q;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    vector<int>ans(q+1);
    vector<edge>queries;

    for(int i=1;i<=q;i++){
        int l, r, id;
        cin>>l>>r;
        id = i;
        queries.push_back({l,r,id});
    }
    sort(queries.begin(), queries.end(), comp);

    vector<int>freq(n+1), emt(n+1);
    int L,R;
    L = queries[0].l;
    R = L;  
    set<pair<int, int>> s; // count, num
    int mx = 0;
    for(auto e: queries){
        int l = e.l;
        int r = e.r;
        int id = e.id;

        if(l!=L){
            s.clear();
            L = l;
            R = l;
            freq = emt;
        }
        for(int i = R ; i<=r ;i++){
            if(freq[arr[i]]==0){
                freq[arr[i]]++;
                s.insert({1,arr[i]});
            }
            else{
                s.erase({freq[arr[i]], arr[i]});
                s.insert({freq[arr[i]]+1, arr[i]});
                freq[arr[i]]++;
            }
            mx = (*s.rbegin()).second;

        }
   
        ans[id] = mx;

    }
    for(int i=1;i<=q;i++){
        cout<<ans[i]<<"\n";
    }

    



    return 0;
}