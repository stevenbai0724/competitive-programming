//https://codeforces.com/contest/1515/problem/B
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
    vector<int>pow2;
    pow2.push_back(2);
    int cur = 2;
    for(int i=1;i<=32;i++){
        cur*=2;
        pow2.push_back(cur);
    }
    vector<int>roots;
    for(int i=1;i<=31623;i++){
        roots.push_back(i*i);
    }

    while(t--){
        int n; cin>>n;
        if(count(pow2.begin(), pow2.end(), n)!=0){
            cout<<"YES\n";
            continue;
        }
        for(int i=0;i<30;i++){
            
            if(n%pow2[i]==0){
                int num = n/pow2[i];
                auto it = lower_bound(roots.begin(), roots.end(), num);
                if(*it==num){
                    cout<<"YES\n";
                    goto nxt;
                }
            }

        }
        cout<<"NO\n";
        nxt:;
    }
    
    
    return 0;
}