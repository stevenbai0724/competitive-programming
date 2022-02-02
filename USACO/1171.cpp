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
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    stack<pair<int, int>>s; //val, ind
    int ans = 0;
    for(int i=1;i<=n;i++){
        int cnt = 0;
        while(!s.empty()){
            if(s.top().first < arr[i]){
                cnt += abs(s.top().second - i) +1;
                s.pop();
            }
            else break;
        }
        if(!s.empty()){
            cnt += abs(s.top().second - i) +1;
        }
        ans += cnt;

        s.push({arr[i], i});
    }
    cout<<ans<<"\n";

    return 0;
}
