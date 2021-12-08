//https://dmoj.ca/problem/dmopc20c1p4
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

    int n, k, t, c;
    cin>>n>>k>>t>>c;

    vector<pair<int, int>>arr(n+1);

    arr[1] = {c, 0};

    const int mod = 1e9 + 7;

    for(int i=2;i<=n;i++){
        arr[i] = arr[i-1];
        arr[i].second += (arr[i-1].first * k)%mod;
        arr[i].second%=mod;
        if(i-1-t>=1){
            arr[i].first += (arr[i-1-t].first * k)%mod;
            arr[i].first %= mod;
            while(arr[i].second < 0){
                arr[i].second += mod;
            }
            arr[i].second -= (arr[i-1-t].first * k)%mod;
        }
        arr[i].first %= mod;
        while(arr[i].second < 0){
                arr[i].second += mod;
        }
        arr[i].second%=mod;
    }
    cout<<((arr[n].first*2)%mod + arr[n].second)%mod<<"\n";


    return 0;
}