//https://cses.fi/problemset/task/1073
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    multiset<int>s;
    while(n--){
        int x; cin>>x;
        auto it = s.upper_bound(x);

        if(it==s.end())s.insert(x);
        else{
            s.erase(it);
            s.insert(x);
        }
    }
    cout<<s.size();
    return 0;
}