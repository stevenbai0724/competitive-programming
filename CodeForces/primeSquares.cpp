#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    for(t; t>0; t--){
        int n; cin>>n;
        vector<vector<int>>arr(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            arr[i][i] = 1;
            arr[i][(i+1)%n] = 1;
        }
        for (int i = 0; i < n; i++) {
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    
    }

    return 0;
}
