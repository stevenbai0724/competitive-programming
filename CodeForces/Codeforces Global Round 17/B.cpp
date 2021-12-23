//https://codeforces.com/contest/1610/problem/B
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
bool check(vector<int>arr){
    int n = arr.size();
    bool good = true;

    for(int i=0;i<n;i++){
        if(arr[i] != arr[n-i-1])good = false;
    }
    return good;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(check(arr)){
            cout<<"YES\n";
            continue;
        }
        vector<int>arr1, arr2;
        int A, B;

        for(int i=0;i<n;i++){
            if(arr[i] != arr[n-i-1]){
                A = arr[i];
                B = arr[n-i-1];
                break;
            }
        }

        for(int i=0;i<n;i++){
            if(arr[i]!=A)arr1.push_back(arr[i]);
            if(arr[i]!=B)arr2.push_back(arr[i]);
        }
        if(check(arr1) || check(arr2))cout<<"YES\n";
        else cout<<"NO\n";


    }

    return 0;
}