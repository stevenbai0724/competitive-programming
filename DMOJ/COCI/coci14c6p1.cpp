//https://dmoj.ca/problem/coci14c6p1
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

    int n, x;
    cin>>n>>x;
    vector<pair<int, int>>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    for(int i=1;i<n;i++){
        if(arr[i].second ^ arr[i+1].second == 1){
            if(arr[i].second == 1){
                if(arr[i].first > arr[i+1].first){
                    int temp = arr[i].first;
                    arr[i].first = arr[i+1].first;
                    arr[i+1].first = temp;
                }
            }
            else{
                if(arr[i].first < arr[i+1].first){
                    int temp = arr[i].first;
                    arr[i].first = arr[i+1].first;
                    arr[i+1].first = temp;
                }
            }
        }
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(arr[i].first <= x && arr[i].second == 1)cnt++;
        else if(arr[i].first > x && arr[i].second == 0)cnt++;
    }
    cout<<cnt<<"\n";

    return 0;
}