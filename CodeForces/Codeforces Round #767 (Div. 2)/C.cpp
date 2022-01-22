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

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>arr(n+3);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

        vector<int>sfx(n+4);
        vector<int>pfx(n+4);
        set<int>s, s2;

        for(int i=0;i<=n;i++){
            s.insert(i);
            s2.insert(i);
        }

        for(int i=n;i>=1;i--){
            s.erase(arr[i]);
            sfx[i] = *s.begin();
        }

        vector<int>ans;
        for(int i=1;i<=n;i++){
            int j = i;
            set<int>add;
            add.insert(arr[i]);
            s2.erase(arr[i]);

            while(*s2.begin() != sfx[i] && j < n){
                j++;
                s2.erase(arr[j]);
                add.insert(arr[j]);
            }
                  
            ans.push_back(sfx[i]);

            for(int k: add)s2.insert(k);

            i = j;

        }
        cout<<ans.size()<<"\n";
        for(int x: ans)cout<<x<<" ";
        cout<<"\n";

    }

    return 0;
}
