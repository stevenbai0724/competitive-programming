//https://dmoj.ca/problem/ichb2017p3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
#define set tree < int ,  null_type ,  less<int> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin>>n>>q;
    vector<set>ans(33);
    for(int i=0;i<=32;i++){
        ans[i].insert(1e18);
    }
    for(int i=1;i<=n;i++){  
        int x; cin>>x;
        for(int j=0;j<=31;j++){
            if(((int)1<<(int)j)&x){
                ans[j+1].insert(i);
            }
        }
    }
    while(q--){
        char c; cin>>c;
        if(c=='Q'){
            int cnt = 0;
            int x, y, val;
            cin>>x>>y>>val;

            for(int j=0;j<=31;j++){
                if(((int)1<<(int)j)&val){
                    auto temp = ans[j+1];
                    auto HI = temp.lower_bound(y);
                    auto LO = temp.lower_bound(x);
                    if(*HI==y && *LO==x){
                        if((int)(temp.order_of_key(y)-temp.order_of_key(x)) == y-x){
                            cnt += ((int)1<<(int)j);
                        }
                    }
                }
            }
            cout<<cnt<<"\n";

        }
        else{
            int x, val;
            cin>>x>>val;
            for(int i=1;i<=32;i++){
                ans[i].erase(x);
            }
            for(int j=0;j<=31;j++){
                if(((int)1<<(int)j)&val){
                    ans[j+1].insert(x);
                }
            }
        }
    }
 




    return 0;
}