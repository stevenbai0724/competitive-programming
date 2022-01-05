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

    string s; cin>>s;
    set<int>st;

    int n = s.length();

    for(int i=0;i<n;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            int j=i;
            string cur = "";
            cur += s[j];
            while(j<n-1 && s[j+1] >= '0' && s[j+1] <= '9'){
                j++;
                cur += s[j];
            }
            st.insert(stoi(cur));
            i=j;
        }
    }
    cout<<st.size()<<"\n";



    return 0;
}
