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
int mod = 1e9 + 7;
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>power(302);

    power[0] = 1;

    for(int i=1;i<=301;i++){
        power[i] = power[i-1] * 2;
        power[i] %= mod;
    }

    int m, n;
    cin>>m>>n;

    vector<int>arr(n+1), ans(n+1);
    string s; cin>>s;
    for(int i=1;i<=n;i++){
        char c = s[i-1];
        if(c == 'N')arr[i] = 1;
    } 

    for(int i=1;i<=n;i++){
        int p = 1;
        vector<int>temp = arr;
        if(temp[i] == 0)temp[i] = 1;
        else temp[i] = 0;

        for(int j=1;j<=n;j++){
            int k = j;
            while(k < n && temp[k+1] == temp[j]){
                k++;
            }
            int len = k-j+1;
            p *= power[len-1];
            p %= mod;
            j = k;
        }
        ans[i] = p;

    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<"\n";


    return 0;
}
