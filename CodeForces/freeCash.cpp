#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int ans = 0;
    int n; cin>>n;
    vector<vector<int>>arr(24, vector<int>(60));

    for(int i =0;i<n;i++){
        int x, y;
        cin>>x>>y;
        arr[x][y]++;
        ans = max(arr[x][y], ans);
    }
    cout<<ans;


    return 0;
}