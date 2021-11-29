//https://codeforces.com/problemset/problem/701/C
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

    int n; cin>>n;
    string s; cin>>s;
    set<char>st;

    for(char c: s)st.insert(c);

    int sz = st.size();

    int j = 0;
    int diff = 1;
    vector<int>freq(123);
    freq[s[0]]++;
    int mn = 1e18;
    for(int i=0;i<n;i++){
        if(i>0){
            freq[s[i-1]]--;
            if(freq[s[i-1]] == 0)diff--;
        }
        j = max(j, i);
        while(j+1<n && diff < sz){
            j++;
            freq[s[j]]++;
            if(freq[s[j]] == 1)diff++;
        }
        if(diff == sz)mn = min(mn, j-i+1);    

    }
    cout<<mn<<"\n";


    return 0;
}