//
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
void solve(int n, vector<int>arr, vector<bool>use){
    if(arr.size() == n+1){
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!use[i]){
            vector<int>temp = arr;
            vector<bool>temp2 = use;
            temp.push_back(i);
            temp2[i] = true;

            solve(n, temp, temp2);
        }
    }
    return;

}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<bool>use(5);

    solve(4, {0}, use);



    return 0;
}
