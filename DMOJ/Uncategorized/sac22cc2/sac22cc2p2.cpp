//https://dmoj.ca/problem/sac22cc2p2
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

    int n, q;
    cin>>n>>q;

    vector<vector<int>>cookie(n+2, vector<int>(n+2));
    vector<vector<int>>sprinkle(n+2, vector<int>(n+2));
    int cnt = 0;
    while(q--){
        int op; cin>>op;

        if(op == 1){
            int x, y;
            cin>>x>>y;
            cookie[x][y]++;
        }
        else{
            int a, b, c, d;
            cin>>a>>b>>c>>d;
            for(int i=a;i<=c;i++){
                for(int j=b;j<=d;j++){
                    cnt += cookie[i][j];
                }
            }
        }

    }
    cout<<cnt<<"\n";


    return 0;
}