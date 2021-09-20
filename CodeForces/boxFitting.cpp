//https://codeforces.com/problemset/problem/1498/B
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool comp(int a, int b){
    return a>b;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        
        int n, w;
        cin>>n>>w;

        multiset<int>s;

        for(int i=1;i<=n;i++){
            int x; cin>>x;
            s.insert(x);
        }
        int cur = w;
        int ans = 1;
        while(!s.empty()){
            auto it = s.upper_bound(cur);

            if(it==s.begin()){
                cur = w;
                ans++;
            }
            else{
                it--;
                int val = *it;
                cur -= val;
                s.erase(it);
            }
        }
        cout<<ans<<"\n";

        
    }

    return 0;
}