//http://www.usaco.org/index.php?page=viewproblem2&cpid=573
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

    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);

    int n; cin>>n;

    set<int>s, useFirst, useSecond;
    for(int i=1;i<=2*n;i++)s.insert(i);
    vector<int>first_half, second_half;
    for(int i=1;i<=n;i++){
        int x; cin>>x;

        if(i<=n/2)first_half.push_back(x);
        else second_half.push_back(x);

        s.erase(x);
    }

    sort(first_half.begin(), first_half.end(), greater<int>());
    sort(second_half.begin(), second_half.end());

    int cnt = 0;
    int ind = 1;
    for(int x: s){
        if(ind<=n/2)useSecond.insert(-x);
        else useFirst.insert(x);
        ind++;
    }

    for(int x: first_half){
        auto it = useFirst.lower_bound(x);
        if(it != useFirst.end()){
            cnt++;
            useFirst.erase(it);
        }
    }
    for(int x: second_half){
        auto it = useSecond.lower_bound(-x);
        if(it!=useSecond.end()){
            cnt++;
            useSecond.erase(it);
        }
    }
    cout<<cnt<<"\n";





    return 0;
}