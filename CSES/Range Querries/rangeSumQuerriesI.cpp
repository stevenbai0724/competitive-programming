//https://cses.fi/problemset/task/1646
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, q;
    cin>>n>>q;
    vector<int>arr(n+1);
    vector<int>psa(n+1);
    int sum = 0;

    for(int i =1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        sum+=arr[i];
        psa[i]=sum;
    }
    while(q--){
        int a,b; cin>>a>>b;
        cout<<psa[b]-psa[a-1]<<"\n";
    }

    return 0;
}
