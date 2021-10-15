//https://dmoj.ca/problem/coci14c5p3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;

    int mod = 2e5+10;

    vector<int>row(1e5+2), col(1e5+2);

    vector<int>up(5e5), down(5e5);

    for(int i=1;i<=n;i++){
        int x, y;
        cin>>x>>y;
        row[y]++;
        col[x]++;
        up[y-x+mod]++;
        down[x+y]++;

        if(row[y]==k || col[x]==k || up[y-x+mod]==k || down[x+y]==k){
            cout<<i<<"\n";
            return 0;
        }


    }
    cout<<-1<<"\n";




    return 0;
}