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

    int n, m, s, f, l, r;
    cin>>n>>m>>s>>f>>l>>r;

    vector<vector<bool>>ans(n+1, vector<bool>(m+1));
    bool found = false;

    vector<int>arr(m+1);
    vector<int>pfx(m+2);
    vector<int>sfx(m+2);

    for(int i=1;i<=m;i++){
        int num;
        cin>>num;

        if(num == f){
            found = true;
        }
        arr[i] = num;
    }

    for(int i=1;i<=m;i++){
        pfx[i] = pfx[i-1];
        pfx[i] += (arr[i] ==s);
    }
    for(int i=m;i>=1;i--){
        sfx[i] = sfx[i+1];
        sfx[i] += (arr[i] ==f);
    }

    if((r == 0 && s == f) || s == f){
        cout<<0<<"\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<"0";
                if(j<m)cout<<" ";
            }
            cout<<"\n";
        }
        return 0;
    }
    else if(r == 0){
        cout<<-1<<"\n";
        return 0;
    }

    if(!found)cout<<-1<<"\n";
    else {
        int cnt = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i == s){

                }
            }
        }



        cout<<1<<"\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<ans[i][j];
                if(j<m)cout<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}   