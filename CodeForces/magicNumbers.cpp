//https://codeforces.com/contest/320/problem/A
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

    string s; cin>>s;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i] != '1' && s[i] != '4'){
            cout<<"NO\n";
            return 0;
        }
    }
    if(s[0] != '1'){
        cout<<"NO\n";
    }

    else{
        for(int i=0;i<n;i++){
            int j = i;
            if(s[i] == '1')continue;
            while(j < n-1 && s[j+1] == '4')j++;

            if(j-i >1){
                cout<<"NO\n";
                goto nxt;
            }
            i = j;
        }
        cout<<"YES\n";
        nxt:;

        
    }

    return 0;
}