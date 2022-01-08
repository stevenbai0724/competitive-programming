//https://dmoj.ca/problem/coci20c6p3
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
    const int mod = 1e9 + 7;
    vector<string>arr;

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        sort(s.begin(), s.end());
        arr.push_back(s);
    }

    sort(arr.begin(), arr.end());
    int ans = 0;
    for(int i=0; i<(1<<n); i++){
        vector<string>temp;
        for(int j=0;j<n;j++){
            if((1<<j)&i)temp.push_back(arr[j]);
        }
        int cnt = 0;
        for(int i=0;i<temp.size();i++){
            int j = i;
            while(j < temp.size() - 1 && temp[j+1] == temp[j]){
                j++;
            }
            int len = j-i+1;
            cnt += (len-1)*(len)/2;
            i = j;
        }

        if(cnt == k)ans++;
    
    }
    cout<<ans<<"\n";

    return 0;
}
