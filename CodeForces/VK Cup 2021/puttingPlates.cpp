//
#include <bits/stdc++.h>
using namespace std;

#define int long long


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;

        vector<int>dx{1,-1,0,0,1,-1,1,-1};
        vector<int>dy{0,0,-1,1,-1,1,1,-1};

        vector<vector<int>>arr(n+2, vector<int>(m+2));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr[i][j] == 0 && (i==1 || j==1 || i==n || j==m)){
                    bool found = true;
                    for(int k=0;k<8;k++){
                        int newx = dx[k] + i;
                        int newy = dy[k] + j;
                        if(arr[newx][newy]==1)found = false;

                    }
                    if(found)arr[i][j] = 1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<arr[i][j];
            }
            cout<<"\n";
        }

    }    

    return 0;
}