//https://dmoj.ca/problem/dmopc16c3p2
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

    int n, k, d;
    cin>>n>>k>>d;

    vector<int>arr(n+1);
    vector<bool>vis(n+1);

    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(c == 'B'){
            cin>>arr[i];
        }
        else{
            arr[i] = 1;
            vis[i] = true;
        }
    }

    bool good = true;

    vector<int>sfx(n+2);
    sfx[n+1] = 1;
    for(int i=n;i>=1;i--){
        if(good){
            sfx[i] = sfx[i+1] * arr[i];
            if(sfx[i] > d){
                sfx[i] = -1;
                good = false;
            }
        }
        else{
            sfx[i] = -1;
        }
    }
    for(int i=1;i<=n;i++){
        assert(sfx[i] >= -1);
        if(vis[i]){
            if(sfx[i] == -1){
                cout<<"dust\n";
            }
            else cout<<sfx[i]<<"\n";
        }
    }

    return 0;
}
