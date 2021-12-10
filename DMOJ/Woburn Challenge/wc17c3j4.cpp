//https://dmoj.ca/problem/wc17c3j4
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

    int n, m;
    cin>>n>>m;
    vector<vector<char>>arr(n+2, vector<char>(m+2));

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        assert((int)s.length() == m);
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
        }
    }
    string top, bottom;
    cin>>top>>bottom;

    for(char &c: top){
        if(c == '_')c = ' ';
    }
    for(char &c: bottom){
        if(c == '_')c = ' ';
    }

    int len1 = top.length();
    int len2 = bottom.length();

    if(m&1){
        int ind = 0;
        for(int i = (m/2)+1 - (len1/2); ind<len1 ; i++,ind++){
            if(top[ind] == ' ')continue;
            arr[2][i] = top[ind];
        }
        ind = 0;
        for(int i= (m/2)+1 - (len2/2); ind<len2; i++, ind++){
            if(bottom[ind] == ' ')continue;
            arr[n-1][i] = bottom[ind];
        }
    }
    else{
        int ind = 0;
        for(int i=(m/2) - (len1-1)/2; ind<len1; i++, ind++){
            if(top[ind] == ' ')continue;
            arr[2][i] = top[ind];
        }
        ind = 0;
        for(int i=(m/2) - (len2-1)/2; ind<len2; i++, ind++){
            if(bottom[ind] == ' ')continue;
            arr[n-1][i] = bottom[ind];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }


    return 0;
}