//https://codeforces.com/problemset/problem/625/C
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

    int n, k;
    cin>>n>>k;
    vector<vector<int>>arr(n+1, vector<int>(n+1));

    int cur = n*(k-1) + 1;
    for(int i=1;i<=n;i++){
        for(int j=k;j<=n;j++){
            arr[i][j] = cur;
            cur++;
        }
    }
    cur = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k-1;j++){
            arr[i][j] = cur;
            cur++;
        }
    }
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum += arr[i][k];
    }
    cout<<sum<<"\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}