//https://codeforces.com/problemset/problem/1366/C
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

        vector<vector<int>>cnt(2, vector<int>((n+m)/2 +1));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>arr[i][j];
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int ind = i+j-1;
                if(ind > (n+m)/2)ind = (n+m)-ind;

                if(arr[i][j]==0)cnt[0][ind]++;
                else cnt[1][ind]++;
            }
        }
        int ans = 0;
        for(int i=1;i<=(n+m-1)/2;i++){
            ans += min(cnt[0][i], cnt[1][i]);
        }
        cout<<ans<<"\n";


    }

    return 0;
}