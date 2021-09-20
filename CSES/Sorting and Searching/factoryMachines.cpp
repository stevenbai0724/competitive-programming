//https://cses.fi/problemset/task/1620
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, t;
vector<int>arr;
bool good(int x){
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum += x/arr[i];
        if(sum>=t)break;
    }
    return sum>=t;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>t;
    arr.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int l=0;
    int r = 2e18;
    while(l+1<r){
        int m = (l+r)/2;
        if(good(m))r = m;
        else l = m;
    }
    cout<<r<<"\n";
    return 0;
}