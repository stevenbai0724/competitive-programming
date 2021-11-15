//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    vector<int>city(n+1), tower(m+1);
    for(int i=1;i<=n;i++){
        cin>>city[i];
    }
    for(int i=1;i<=m;i++){
        cin>>tower[i];
    }

    int mn = abs(city[1]-tower[1]);
    int mx = 0;
    int j = 1;
    for(int i=1;i<=n;i++){
        int curCity = city[i];
        mn = abs(curCity-tower[j]);
        while(j<m && abs(curCity-tower[j+1])<=mn){
            j++;
            mn = abs(curCity-tower[j]);
        }
        mx = max(mx, mn);
    }
    cout<<mx<<"\n";
    
    

    return 0;
}