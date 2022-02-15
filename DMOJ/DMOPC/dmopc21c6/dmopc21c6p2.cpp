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
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;
    string s; cin>>s;

    vector<int>seg;

    for(int i=0;i<n;i++){
        int j = i;
        if(s[i] == '0'){
            while(j<n-1 && s[j+1] == '0')j++;

            seg.push_back(j-i+1);
            i = j;
        }
        
    }
    sort(seg.begin(), seg.end(), [] (int a, int b){
        return a > b;
    });

    int sz = seg.size();
    int ans = 0;
    for(int i=0;i<min(sz, k);i++){
        ans += seg[i];
    }

    cout<<ans<<"\n";


    return 0;
}
