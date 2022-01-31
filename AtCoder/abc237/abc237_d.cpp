//https://atcoder.jp/contests/abc237/tasks/abc237_d
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
    string s; cin>>s;

    vector<pair<int, int>>arr(n+1);

    for(int i=0;i<=n;i++){
        arr[i] = {-1,-1};
    }

    for(int i=0;i<n;i++){
        if(s[i] == 'L'){
            if(arr[i].first == -1){
                arr[i].first = i+1;
                arr[i+1].second = i;
            }
            else{
                int OGLEFT = arr[i].first;
                arr[OGLEFT].second = i+1;
                arr[i].first = i+1;
                arr[i+1].first = OGLEFT;
                arr[i+1].second = i;
            }
        }
        else{
            if(arr[i].second == -1){
                arr[i].second = i+1;
                arr[i+1].first = i;
            }
            else{
                int OGRIGHT = arr[i].second;
                arr[OGRIGHT].first = i+1;
                arr[i].second = i+1;
                arr[i+1].second = OGRIGHT;
                arr[i+1].first = i;

            }
        }
    }
    int cur = 0;
    for(int i=0;i<=n;i++){
        if(arr[i].first == -1)cur = i;
    }

    while(cur != -1){
        cout<<cur<<" ";
        cur = arr[cur].second;
    }
    cout<<"\n";

    return 0;
}
