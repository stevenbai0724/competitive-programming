//https://dmoj.ca/problem/gfssoc2j5
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin>>n>>q;
    vector<bool>use(11);
    vector<int>arr(n+1);
    vector<vector<int>>freq(n+2, vector<int>(11));

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        use[arr[i]] = true;
        for(int j=1;j<=10;j++){
            freq[i][j] = freq[i-1][j];
        }
        freq[i][arr[i]] ++;
    }
    for(int i=1;i<=10;i++){
        freq[n+1][i] = freq[n][i];
    }
    while(q--){
        int x, y;
        cin>>x>>y;
        for(int i = 10;i>=1;i--){
            if(use[i]){
                int deleted = freq[y][i] - freq[x-1][i];
                if(freq[n][i]-deleted>0){
                    cout<<i<<" "<<freq[n][i]-deleted<<"\n";
                    goto nxt;
                }
            }
        }
        nxt:;
    }





    return 0;
}