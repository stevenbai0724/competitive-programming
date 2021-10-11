//https://codeforces.com/contest/1579/problem/B
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

struct edge{
    int a, b, d;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>arr(n+1), sorted;
        arr[0] = -1e18;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        sorted = arr;
        sort(sorted.begin(), sorted.end());
        vector<edge>ans;
        for(int i=1;i<=n;i++){
            if(sorted[i]==arr[i])continue;
            for(int j=i;j<=n;j++){
                if(arr[j]==sorted[i]){
                    ans.push_back({i,j,j-i});
                    for(int k=j;k>i;k--){
                        arr[k] = arr[k-1];
                    }
                    arr[i] = sorted[i];
                    break;
                }
            }
        }
        assert(arr==sorted);
        cout<<ans.size()<<"\n";
        for(auto e: ans){
            cout<<e.a<<" "<<e.b<<" "<<e.d<<"\n";
        }
    }


    return 0;
}