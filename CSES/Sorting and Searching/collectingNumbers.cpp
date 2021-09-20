//https://cses.fi/problemset/task/2216
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    multiset<int>arr;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        auto it = arr.find(x-1);
        if(it==arr.end())arr.insert(x);
        else {
            arr.erase(it);
            arr.insert(x);
        }
    }
    cout<<arr.size()<<"\n";
    
   
    return 0;

}