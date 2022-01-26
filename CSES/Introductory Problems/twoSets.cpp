//https://cses.fi/problemset/task/1073
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

    int n; cin>>n;

    if((n*(n+1)/2) & 1){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    set<int>s;
    for(int i=1;i<=n;i++){
        s.insert(i);
    }

    if(n&1){
        cout<<n/2<<"\n";
        cout<<n<<" ";
        s.erase(n);
        for(int i=1;i<=n/4;i++){
            s.erase(i);
            s.erase(n-i);
            cout<<i<<" "<<n-i<<" ";
        }
        cout<<"\n";
        cout<<s.size()<<"\n";
        for(int x: s)cout<<x<<" ";
        cout<<"\n";
    }
    else{
        cout<<n/2<<"\n";
        for(int i=1;i<=n/4;i++){
            cout<<i<<" "<<n-i+1<<" ";
            s.erase(i);
            s.erase(n-i+1);
        }
        cout<<"\n";
        cout<<n/2<<"\n";
        for(int x: s)cout<<x<<" ";
        cout<<"\n";
    }

    return 0;
}
