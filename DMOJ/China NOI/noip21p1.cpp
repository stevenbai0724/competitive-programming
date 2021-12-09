//https://dmoj.ca/problem/noip21p1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
bool hasSeven(int n){
    string s = to_string(n);
    bool found = false;
    for(auto c: s)if(c == '7')found = true;

    return found;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n = 1e7+1e4;
    vector<bool>bad(n+1);
    set<int>s;
    vector<int>temp;
    for(int i=1;i<=n;i++){
        if(bad[i])continue;
        if(hasSeven(i)){
            bad[i] = true;
            for(int j=2;j*i<=n;j++){
                bad[j*i] = true;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!bad[i]){
            s.insert(i);
            temp.push_back(i);
        }
    }

    for(int x: temp){
        for(int i=2;i*i<=x;i++){
            if(x%i == 0){
                int a = i;
                int b = x/i;
                if(bad[a] || bad[b]){
                    bad[x] = true;
                    s.erase(x);
                    break;
                }
            }
        }
    }

    int t; cin>>t;
    while(t--){
        int x; cin>>x;
        if(bad[x])cout<<-1<<"\n";
        else{
            cout<<*s.upper_bound(x)<<"\n";
        }
    }
    


    return 0;
}