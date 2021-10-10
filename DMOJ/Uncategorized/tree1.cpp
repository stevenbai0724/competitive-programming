//https://dmoj.ca/problem/tree1
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    vector<vector<int>>arr(5, vector<int>(5));
    int n = 4;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(arr[i][j]==1){
                if(arr[i][j]==1 && arr[j][i]==1)cnt++;
                else{
                    cout<<"No\n";
                    return 0;
                }
            }
            
        }
    }
    
    for(int i=1;i<=n;i++){
        bool good = false;
        for(int j=1;j<=n;j++){
            if(arr[i][j]==1){
                good = true;
                break;
            }
        }
        if(!good){
            cout<<"No\n";
            return 0;
        }
    }
    if(cnt==6)cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}