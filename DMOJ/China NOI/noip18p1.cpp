//https://dmoj.ca/problem/noip18p1
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

    int n; cin>>n;
    vector<int>arr(n+2);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        int j = i;
        while(j<n && arr[j+1]>=arr[j]){
            j++;
        }
        cnt += arr[j];

        while(j<n && arr[j+1]<=arr[j])j++;

        int cur = arr[j];
        int k = j;

        while(k<n ){
            k++;
            cur = min(cur, arr[k]);
            arr[k] -= cur;
        }

        i = j;

    }
    cout<<cnt<<"\n";



    return 0;
}