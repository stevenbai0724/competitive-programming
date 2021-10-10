//https://dmoj.ca/problem/dmopc17c4p2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

int n, q;
vector<vector<int>>adj;
vector<int>parent;
vector<int>colour;
vector<int>weight;
vector<int>path;

void clear(){
    fill(parent.begin(), parent.end(), 0);
    fill(colour.begin(), colour.end(), 0);
    path.clear();
}
void dfs(int v){
    colour[v] = 1;
    for(int u: adj[v]){
        if(colour[u]==0){
            parent[u] = v;
            dfs(u);
        }
    }
    colour[v] = 2;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);


    cin>>n>>q;
    adj.resize(n+1);
    parent.resize(n+1);
    colour.resize(n+1);
    weight.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>weight[i];
    }

    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    while(q--){
        int p, a, b;
        cin>>p>>a>>b;
        if(a==b){
            cout<<weight[a]<<"\n";
            continue;
        }
        dfs(a);
        path.push_back(b);
        int nxt = parent[b];
        while(true){
            path.push_back(nxt);
            if(nxt==a)break;
            nxt = parent[nxt];
        }
        vector<int>vals;
        for(auto x: path){
            vals.push_back(weight[x]);
        }

        sort(vals.begin(), vals.end());
        int len = vals.size();

        if(p==1){
            double sum = 0;
            for(int x: vals){
                sum += x;
            }
            cout<<round(sum/(double)len)<<"\n";
        }
        if(p==2){
            int L = (len-1)/2;
            int R = len/2;
            cout<<round((vals[L]+vals[R])/2.0)<<"\n";
        }
        if(p==3){
            vector<int>freq(1e5+4);
            int mx = 0;
            int mn = 1e18;
            for(int x: vals){
                assert(x<=1e5);
                freq[x]++;
                if(freq[x]==mx){
                    mn = min(mn, x);
                }
                else if(freq[x]>mx){
                    mx = freq[x];
                    mn = x;
                }

                
            }
            cout<<mn<<"\n";
        }



        clear();


    }




    return 0;
}