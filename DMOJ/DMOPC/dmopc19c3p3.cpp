//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+2);
    vector<int>psa(n+2);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        psa[i] = psa[i-1];
        if(arr[i]==1)psa[i]++;
 
    }
    psa[n+1] = psa[n];
    int cnt = 0;
    for(int l=0;l<=n-1;l++){
        for(int r = n;r>l;r--){
            int len = r-l;
            int val = psa[r]-psa[l];
            if(val*2>=len+1)cnt++;
        }
    }
    cout<<cnt<<"\n";


    return 0;
}