//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        
        vector<vector<int>>skill(n+1);
        vector<vector<int>>psa(n+1);
        vector<int>ans(n+1);
        vector<int>uni(n+1);

        for(int i=1;i<=n;i++){
            cin>>uni[i];
        }
        for(int i=1;i<=n;i++){
            int x; cin>>x;
            skill[uni[i]].push_back(x);
        }
        for(int i=1;i<=n;i++){
            sort(skill[i].begin(), skill[i].end(), greater<int>());
        }


        for(int i=1;i<=n;i++){
            int sum = 0;
            for(auto x: skill[i]){
                sum+=x;
                psa[i].push_back(sum);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=skill[i].size();j++){
                int take = skill[i].size()/j * j;
                ans[j] += psa[i][take-1];
            }
        }
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";



    }

    return 0;
}