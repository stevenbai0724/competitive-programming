//https://dmoj.ca/problem/mockccc14s3
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
     
    int n, m;
    cin>>n>>m;

    vector<vector<int>>arr(n+1, vector<int>(m+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }

    int q; cin>>q;
    while(q--){
        int x; cin>>x;
        
        while(true){
            bool sort = true;
            for(int i=1;i<n;i++){
                if(arr[i][x]>arr[i+1][x]){
                    sort = false;
                    for(int k=1;k<=m;k++){
                        int temp = arr[i][k];
                        arr[i][k] = arr[i+1][k];
                        arr[i+1][k] = temp;
                    }    
                }
            }
            if(sort)break;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}