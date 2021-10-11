//https://dmoj.ca/problem/bts18p2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string temp; getline(cin, temp);
    string s = " ";
    s += temp;

    int n = s.length();
    vector<vector<int>>psa(26, vector<int>(n+1));
    for(int i=1;i<n;i++){
        for(int j=0;j<26;j++){
            psa[j][i] = psa[j][i-1];
        }
        if(s[i]!= ' ')psa[((int)s[i])-97][i]++;
 
    }

    int t; cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        char c; cin>>c;

        cout<<psa[c-97][b] - psa[c-97][a-1]<<"\n";
    }

    return 0;
}