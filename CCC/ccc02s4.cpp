//
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

    int m; cin>>m;
    int n; cin>>n;
    vector<pair<int, int>>dp(n+1);
    vector<int>arr(n+1);

    map<int, string>mp;
    map<string, int> mp2;

    for(int i=1;i<=n;i++){  
        string s; cin>>s;
        mp[i] = s;
        mp2[s] = i;
        cin>>arr[i];
    }

    dp[1] = {1,0};

    for(int i=2;i<=n;i++){
        int mx = arr[i];
        dp[i] = {arr[i]+dp[i-1].first, 0};
        int take = 1;
        for(int j=i-1;j>=i-m+1 && j>= 1;j--){
            mx = max(mx, arr[j]);
            if(mx + dp[j-1].first <= dp[i].first){
                dp[i] = {mx + dp[j-1].first, take};
            }
            take ++;
        }
    }
    vector<vector<string>>ans;
    int cnt = 0;
    for(int i=n;i>=1;i--){
        int take = dp[i].second;
   
        vector<string>temp;
        int last;
        int mx = 0;
        for(int j=i;j>=i-take;j--){
            temp.push_back(mp[j]);
            last = j;
            mx = max(mx, arr[i]);
        }

        cnt += mx;

        reverse(temp.begin(), temp.end());
        ans.push_back(temp);
        i = last;
      

    }
    assert(dp[n].first == cnt);

    reverse(ans.begin(), ans.end());
    cout<<"Total Time: "<<dp[n].first<<"\n";
    int cur = 1;
    for(auto v: ans){
        for(auto s: v){
            cout<<s<<" ";
            assert(cur == mp2[s]);
            cur++;
        }
        cout<<"\n";
    }

    return 0;
}