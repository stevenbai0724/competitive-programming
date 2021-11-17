//https://cses.fi/problemset/task/1085
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

    int n, k;
    cin>>n>>k;
    vector<int>arr(n+1);
    int maxsum = 0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        maxsum += arr[i];
    }

    int L = 0;
    int R = maxsum;


    while(L+1<R){
        int m = (L+R)/2; // the max sum allowed in our array
        int used = 0;
        for(int i=1;i<=n;i++){

            int j = i;
            int sum = arr[i];
            while(j<n && sum+arr[j+1]<=m){
                sum += arr[j+1];
                j++;
            }
            if(sum>m){
                L = m;
                goto nxt;
            }
            i = j;
            used++;
            
        }
        if(used>k)L = m;
        else R = m;
        nxt:;

    }
    cout<<R<<"\n";
    

    return 0;
}