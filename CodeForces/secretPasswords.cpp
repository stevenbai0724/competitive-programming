//https://codeforces.com/problemset/problem/1263/D
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string

struct DSU{

    vector<int>parent, sz;


    void init(int n){
        parent.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++){
            sz[i] = 1;
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] == x)return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y)return ;

        if(sz[x]<sz[y]){
            parent[x] = y;
            sz[y] += sz[x];
        }
        else {
            parent[y] = x;
            sz[x] += sz[y];
        }
        
    }

};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<bool>freq(26);
    DSU ds;
    ds.init(26);
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        set<char>temp;
        for(auto ch: s){
            temp.insert(ch);
        }

        int ind = (int)(s[0])-97;
        for(char ch : temp){
            freq[ch-97] = true;

            ds.Union(ind, ch-97);

        }

    }
    set<int>ans;

    for(int i=0;i<26;i++){
        if(freq[i]==0)continue;
        ans.insert(ds.find(i));
    }
    cout<<ans.size()<<"\n";

    return 0;
}