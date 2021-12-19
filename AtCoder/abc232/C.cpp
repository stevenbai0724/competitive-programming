//
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

    vector<vector<bool>>adj1(n+1, vector<bool>(n+1));
    vector<vector<bool>>adj2(n+1, vector<bool>(n+1));

    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        adj1[x][y] = true;
        adj1[y][x] = true;
    }
    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        adj2[x][y] = true;
        adj2[y][x] = true;
    }

    vector<int>arr;
    for(int i=1;i<=n;i++){
        arr.push_back(i);
    }
    bool ans = false;
    bool found = true;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int a = i+1;
            int b = j+1;
            int c = arr[i];
            int d = arr[j];

            if(adj1[a][b] != adj2[c][d])found = false;
            
        }
    }
    if(found)ans = true;
    while(next_permutation(arr.begin(), arr.end())){
        found = true;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int a = i+1;
                int b = j+1;
                int c = arr[i];
                int d = arr[j];

                if(adj1[a][b] != adj2[c][d])found = false;
                
            }
            
        }
    if(found)ans = true;
    }
    cout<<(ans ? "Yes" : "No")<<"\n";





    return 0;
}