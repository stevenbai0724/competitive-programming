//https://codeforces.com/problemset/problem/1619/D
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//order_of_key
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>>arr(n+1, vector<int>(m+1));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>arr[i][j];
            }
        }
        vector<int>mx(m+1);

        for(int j=1;j<=m;j++){
            for(int i=1;i<=n;i++){
                mx[j] = max(mx[j], arr[i][j]);
            }
        }

        int L = 1;
        int R = 1e18;

        while(L+1<R){
            int mid = (L+R)/2;

            bool good = false;

            for(int i=1;i<=n;i++){
                int cnt = 0;
                for(int j=1;j<=m;j++){
                    if(arr[i][j] >= mid)cnt++;
                }
                if(cnt >= 2)good = true;
            }
            if(!good){
                R = mid;
                continue;
            }
            for(int j=1;j<=m;j++){
                if(mx[j] < mid)good = false;
            }
            if(!good){
                R = mid;
            }
            else L = mid;
        }
        cout<<L<<"\n";
    }

    return 0;
}