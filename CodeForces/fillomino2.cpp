//https://codeforces.com/problemset/problem/1517/C
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

    int n; cin>>n;
    vector<vector<int>>arr(n+2, vector<int>(n+2));

    for(int i=1;i<=n;i++){
        cin>>arr[i][i];
    }

    for(int i=n;i>=1;i--){
        int num = arr[i][i];
        int x = i;
        int y = i;
        for(int j=1;j<num;j++){
            if(x + 1 <= n && arr[x+1][y]==0){
                x++;
                arr[x][y] = num;
            }   
            else{
                assert(y>=2);
                y--;
                arr[x][y] = num;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]==0)break;
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
