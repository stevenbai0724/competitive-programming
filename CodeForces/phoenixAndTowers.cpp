//https://codeforces.com/problemset/problem/1515/C
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
        int n, m, x;
        cin>>n>>m>>x;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q; //height, index of tower

        for(int i=1;i<=m;i++){
            q.push({0,i});
        }
        cout<<"YES\n";
        for(int i=1;i<=n;i++){
            int height = q.top().first;
            int ind = q.top().second;
            q.pop();
            int x; cin>>x;

            cout<<ind<<" ";

            q.push({(height + x), ind});


        }
        cout<<"\n";


    }

    return 0;
}
