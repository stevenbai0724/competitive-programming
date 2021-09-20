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
        int n, k;
        cin>>n>>k;

        vector<pair<int, int>>arr(n+1);

        for(int i=1;i<=n;i++){
            int a, b;
            cin>>a>>b;
            arr[i] = {a,b};
        }

        for(int i=1;i<=n;i++){
            int cnt = 0;
            int a = arr[i].first;
            int b = arr[i].second;
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                int x = arr[j].first;
                int y = arr[j].second;
                if(abs(x-a)+abs(y-b)<=k)cnt++;
            }
            if(cnt==n-1){
                cout<<1<<"\n";
                goto nxt;
            }

        }
        cout<<-1<<"\n";
        nxt:;



    }
    
    return 0;
}