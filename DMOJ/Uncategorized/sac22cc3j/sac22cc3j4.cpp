//https://dmoj.ca/problem/sac22cc3jp4
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

    vector<vector<int>>power(11, vector<int>(31));
    vector<int>digits(11,1);

    for(int i=2;i<=10;i++){
        power[i][0] = 1;
    }

    for(int i=2;i<=10;i++){
        for(int j=1;j<=31;j++){
            power[i][j] = power[i][j-1] * i;
            if(power[i][j] > 1e9)break;
            else digits[i]++;
        }
    }
    
    int q; cin>>q;
    while(q--){
        int b1, b2;
        string s;
        cin>>b1>>s>>b2;
        int len = s.length();

        int val = 0;

        for(int i=len-1;i>=0;i--){
            int d = s[len-i-1] - '0';
            val += d*power[b1][i];
        }    
        bool first = true;  
        string ans = "";
        for(int i = digits[b2];i>=0;i--){
            
            int nxt = val/power[b2][i];
            if(nxt !=0 )first = false;
            if(nxt == 0 && first)continue;
            val%=power[b2][i];
            ans += (to_string(nxt));
            
        }
        cout<<ans<<"\n";
    }

    return 0;
}
