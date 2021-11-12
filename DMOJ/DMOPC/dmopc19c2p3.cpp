//https://dmoj.ca/problem/dmopc19c2p3
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
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<BIT>bits(21);
    map<int, int>good;
    int n, q;
    cin>>n>>q;

    for(int i=0;i<=20;i++){
        bits[i].init(n);
    }
    for(int i=1;i<=n;i++){
        int g; cin>>g;
        good[i] = g;
        bits[g].change(i, 1);

    }
 
    while(q--){
  
        int o; cin>>o;
        if(o==1){
            int a, b;
            cin>>a>>b;
            bits[good[a]].change(a, 0);
            good[a] = b;
            bits[b].change(a, 1);
        }
        else{
            int l, r, c;
            cin>>l>>r>>c;
            int cnt = c;
            int ans = 0;
            for(int i=20;i>=0;i--){
                cnt -= bits[i].query(l,r);
                if(cnt<=0){
                    ans = i;
                    break;
                }
            }
            cout<<ans<<"\n";
        }
    }



    return 0;
}