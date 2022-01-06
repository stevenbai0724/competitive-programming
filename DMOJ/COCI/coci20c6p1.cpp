//https://dmoj.ca/problem/coci20c6p1
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

    int n, m;
    cin>>n>>m;
    vector<vector<char>>arr(n+1, vector<char>(m+1));

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            if(s[j-1] == '#'){
                arr[i][j] = '#';
                arr[i+1][j] = '#';
                arr[i][j+1] = '#';
                arr[i+1][j+1] = '#';
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<(arr[i][j] == '#' ? '#' : '.');
        }
        cout<<"\n";
    }

    return 0;
}
