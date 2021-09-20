//https://codeforces.com/problemset/problem/583/A
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int c = 1e9;
    vector<int>arr(n*n+1);
    vector<bool>hor(n+1, false);
    vector<bool>ver(n+1, false);

    for(int i=1;i<=n*n;i++){
        int h, v;
        cin>>h>>v;
        arr[i] = h*c+v;
    }
    for(int i=1;i<=n*n;i++){
        int newh = arr[i]/c;
        int newv = arr[i]%c;

        if(!hor[newh] && !ver[newv]){
            hor[newh] = true;
            ver[newv] = true;
            cout<<i<<" ";
        }
    }
    return 0;
}