//https://codeforces.com/problemset/problem/1231/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int ans = 0;
    cin>>n>>m;
    vector<vector<int>>arr(n+1, vector<int>(m+1));
    vector<int>changeX{1,-1,0,0};
    vector<int>changeY{0,0,-1,1};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(arr[i][j]==0){
                arr[i][j] = min(arr[i+1][j]-1, arr[i][j+1]-1);
            }
            ans +=arr[i][j];
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            for(int k=0;k<=3;k++){
                int newx = i+changeX[k];
                int newy = j+changeY[k];
                if(newx>n || newx<1 || newy>m||newy<1)continue;
                if(k==0 || k==3){
                    if(arr[newx][newy]<=arr[i][j]){
                        cout<<-1;
                        return 0;
                    }
                }
                else{
                    if(arr[newx][newy]>=arr[i][j]){
                        cout<<-1;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<ans;
    

    return 0;
}