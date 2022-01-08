//https://dmoj.ca/problem/bsspc21s3
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

    int n, k;
    cin>>n>>k;

    vector<int>arr(n+1), psa(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        psa[i] = psa[i-1];
        psa[i] += arr[i];
    }   
    int ans = 0;

    for(int i=1;i<=k;i++){
        vector<int>temp;
        for(int j=i+k-1;j<=n;j+=k){
            temp.push_back(psa[j]-psa[j-k]);
        }
        int sum = 0;
        for(int x: temp){
            if(sum < 0)sum = 0;
            sum += x;
            ans = max(ans, sum);
        }

    }
    cout<<ans<<"\n";


    return 0;
}
