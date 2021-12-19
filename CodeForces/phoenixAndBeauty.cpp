//https://codeforces.com/problemset/problem/1348/B
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int>arr(n+1);
        vector<int>seq;
        vector<bool>vis(101);

        for(int i=1;i<=n;i++){
            cin>>arr[i];
            if(!vis[arr[i]]){
                seq.push_back(arr[i]);
            }
            vis[arr[i]] = true;
        }
        if(seq.size() > k){
            cout<<-1<<"\n";
        }
        else{
            if(seq.size() < k){
                for(int i=1;i<=100;i++){
                    if(!vis[i]){
                        seq.push_back(i);
                    }
                    if(seq.size() == k)break;
                }
            }
            cout<<(10000/seq.size())*seq.size()<<"\n";
            for(int i=1;i<=(10000 / seq.size());i++){
                for(int x: seq)cout<<x<<" ";
            }
            cout<<"\n";
        }


    }


    return 0;
}