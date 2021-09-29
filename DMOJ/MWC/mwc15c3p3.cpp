//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

int n, m;
vector<vector<char>>arr;
void solve(){

}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>m;
    arr.resize(n+1);
    for(int i=1;i<=n;i++){
        arr[i].resize(m+1);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }

    solve();





    return 0;
}