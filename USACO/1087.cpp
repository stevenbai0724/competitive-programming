//http://www.usaco.org/index.php?page=viewproblem2&cpid=1087
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

    int n, q;
    cin>>n>>q;
    string s; cin>>s;

    s = " " + s;
    
    vector<int>pfx(n+2), sfx(n+2);

    stack<char>st;

    for(int i=1;i<=n;i++){
        char c = s[i];
        while(!st.empty() && st.top() > c){
            st.pop();
        }    
        if(st.empty()){
            pfx[i] = pfx[i-1] + 1;
            st.push(c);
        }
        else{
            if(st.top() == c){
                pfx[i] = pfx[i-1];
            }
            else{
                pfx[i] = pfx[i-1] + 1;
                st.push(c);
            }
        }
    }
    while(!st.empty())st.pop();
    for(int i=n;i>=1;i--){
        char c = s[i];
        while(!st.empty() && st.top() > c){
            st.pop();
        }    
        if(st.empty()){
            sfx[i] = sfx[i+1] + 1;
            st.push(c);
        }
        else{
            if(st.top() == c){
                sfx[i] = sfx[i+1];
            }
            else{
                sfx[i] = sfx[i+1] + 1;
                st.push(c);
            }
        }
    }
    while(q--){
        int x, y;
        cin>>x>>y;
        cout<<pfx[x-1] + sfx[y+1]<<"\n";
    }

    return 0;
}
