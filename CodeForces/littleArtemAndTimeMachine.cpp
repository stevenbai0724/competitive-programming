//https://codeforces.com/contest/669/problem/E
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
struct BIT{
    vector<int>arr;
    int size;
    void init(int n){
        size = n;
        arr.resize(n+5);
    }
    void update(int x, int val){ //add
        for(int a = x; a<=size; a+=a&-a){
            arr[a]+=val;
        }
    }
    int query(int x){
        int sum = 0;
        for(int a = x; a>0; a-=a&-a){
            sum+=arr[a];
        }
        return sum;
    }
    void change(int x, int val){ //change
        int v = query(x)-query(x-1);
        update(x,val-v);
    }
    int query(int x, int y){//inclusive
        return query(y)-query(x-1);
    }
};
struct edge{
    int q, t, x, i;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    map<int,int> val;

    vector<vector<edge>>queries;
    vector<pair<int, int>>ans;

    int curVal = 1;

    for(int i=1;i<=n;i++){
        int q, t, x;
        cin>>q>>t>>x;

        if(val[x] == 0){
            val[x] = curVal;
            curVal++;
            queries.push_back({{q,t,x,i}});
        }
        else{
            queries[val[x]-1].push_back({q,t,x,i});
        }
     
    }

    for(auto v: queries){
        vector<int>arr{(int)-1e18};
        
        for(auto e: v){
            arr.push_back(e.t);
        
        }
        sort(arr.begin(), arr.end());

        BIT bit;
        bit.init(v.size());

        for(auto e: v){
            int time = lower_bound(arr.begin(), arr.end(), e.t) - arr.begin();
            if(e.q == 1){
                bit.update(time, 1);
            }
            if(e.q == 2){
                bit.update(time, -1);
            }
            if(e.q == 3){
                ans.push_back({e.i, bit.query(1,time)});
            }
        }

        
    }
    sort(ans.begin(), ans.end());

    for(auto p: ans) cout<<p.second<<"\n";


    return 0;
}