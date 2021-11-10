//https://dmoj.ca/problem/ccc17s5
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, q;
    cin>>n>>m>>q;

    vector<int>passenger(n+1);
    vector<vector<int>>line(m+1);
    vector<int>GOTO(n+1);

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        line[x].push_back(i);
    }
    for(int i=1;i<=n;i++){
        cin>>passenger[i];
    }
    for(int i=1;i<=m;i++){
        if(!line[i].empty())line[i].push_back(line[i][0]);
    }
    for(int i=1;i<=m;i++){
        int len = line[i].size();
        for(int j=0;j<len-1;j++){
            GOTO[line[i][j]] = line[i][j+1];
        }
    }

    while(q--){
        int x; cin>>x;
        if(x==1){
            int l, r;
            cin>>l>>r;
            int sum = 0;
            for(int i=l;i<=r;i++){
                sum += passenger[i];
            }
            cout<<sum<<"\n";
        }
        else{
            int y; cin>>y;
            if(line[y].empty())continue;
            int len = line[y].size();
            int nxt = passenger[line[y][0]];
            for(int i=0;i<len-1;i++){
                int temp = passenger[GOTO[line[y][i]]];
                passenger[GOTO[line[y][i]]] = nxt;
                nxt = temp;

            }
   
        }
    }


    return 0;
}