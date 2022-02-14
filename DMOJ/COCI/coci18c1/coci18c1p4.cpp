//
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<vector<char>>arr(n+1, vector<char>(m+1));

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
        }
    }
    int ans = 0;
    for(int x=1;x<=n;x++){
        for(int y = 1; y<=m; y++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(i + x - 1 <=n && j + y-1 <=m){ //cords are good
                        bool good = true;
                        for(int k=i;k<i+x;k++){
                            for(int l=j;l<j+y;l++){
                                if(arr[k][l] == '#')good = false;
                            }
                        }

                        if(good){
                            ans += (x*y);
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<"\n";

    return 0;
}