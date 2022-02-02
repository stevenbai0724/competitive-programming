//
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
struct edge{
    int x, y, id;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    vector<edge>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i].x>>arr[i].y;
        arr[i].id = i;
    }
    sort(arr.begin(), arr.end(), [] (edge a, edge b){
        return a.x < b.x;
    });
    vector<int>ans;
    set<int>s;
    for(int i=1;i<=n;i++){
        s.insert(i);
    }
    int cnt = n;

    for(int i=1;i<=n;i++){
        int x = arr[i].x;
        int y = arr[i].y;
        int id = arr[i].id;
        if(s.find(x) != s.end()){
            cnt--;
            s.erase(x);
        }
        else if(s.find(y) != s.end()){
            s.erase(y);
            cnt--;
        }
        
        ans.push_back(id);
    }
    cout<<cnt<<"\n";
    for(int x: ans)cout<<x<<"\n";


    

    return 0;
}
