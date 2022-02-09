//https://dmoj.ca/problem/ccc21s5
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
struct edge{
    int x, y, z;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<edge>res;
    vector<int>arr(n+1,1);
    for(int i=1;i<=m;i++){
        int x, y, z;
        cin>>x>>y>>z;
        res.push_back({x,y,z});

        for(int j=x;j<=y;j++){
            
            int a = arr[j];
            int GCD = __gcd(a, z);
            int lcm = a*z / GCD;
            arr[j] = lcm;
        }
    }
    bool good = true;
    for(edge e: res){
        int x = e.x;
        int y = e.y;
        int z = e.z;
        int GCD = arr[x];

        for(int i=x;i<=y;i++){
            GCD = __gcd(GCD, arr[i]);
        }

        if(GCD != z) good = false;

    }

    if(good){
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    else cout<<"Impossible\n";


    return 0;
}
