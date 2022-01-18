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
bool composite(int n){
    bool ans = false;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0)ans = true;        
    }
    if(n == 1)ans = true;
    return ans;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    bool found = false;
    vector<int>ans;
    vector<int>arr;

    for(int i=1;i<=n;i++){
        arr.push_back(i);
        ans.push_back(1e18);
    }
    bool temp = true;
    for(int i=0;i<n;i++){
        if(composite(i+1+arr[i]))temp = false;
    }

    if(arr < ans && temp){
        ans = arr;
        found = true;
    }

    while(next_permutation(arr.begin(), arr.end())){
        bool good = true;
        for(int i=0;i<n;i++){
            if(composite(i+1+arr[i]))good = false;
        }
        if(good && arr < ans)ans = arr;
        if(good)found = true;
    }

    if(!found)cout<<-1<<"\n";
    else {
        for(int i=0;i<n;i++){
            cout<<ans[i];
            if(i<n-1)cout<<" ";
        }
        cout<<"\n";
    }
    


    return 0;
}
