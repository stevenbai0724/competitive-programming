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
        if(n == 2){
            cout<<-1<<"\n";
            continue;
        }
        if(n == 4){
            cout<<"3 1 4 2\n";
            continue;
        }
        vector<bool>vis(n+5);
        vector<int>ans{1};
        bool three = true;
        vis[1] = true;
        int cur = 1;
        while(ans.size() < n){
            if(three){
                three =false;
                if(!vis[cur+3] && cur+3 <= n){
                    vis[cur+3] = true;
                    cur += 3;
                    ans.push_back(cur);
                }
            }else{
                three = true;

                if(cur-2>=1 && !vis[cur-2]){
                    vis[cur-2] = true;
                    cur -= 2;
                    ans.push_back(cur);
                }

            }
        }

        for(int i=0;i<n;i++){
            cout<<ans[i];
            if(i < n-1)cout<<" ";
        }
        cout<<"\n";

    }

    return 0;
}