//https://codeforces.com/problemset/problem/1506/D
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

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        priority_queue<int>q;
        sort(arr.begin(), arr.end());
        for(int i=1;i<=n;i++){
            int j = i;
            while(j<n && arr[j+1] == arr[j]){
                j++;
            }
            q.push(j-i+1);
            i = j;
        }
        int ans = 0;
        while(q.size() >= 2){
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            ans += 2;
            a--;
            b--;
            if(a>0)q.push(a);
            if(b>0)q.push(b);
        }
        cout<<n - ans<<"\n";


    }

    return 0;
}
