#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int c = (1e9+7);
    int ans, n;
    ans = 1;
    cin>>n;
    for(int i =1;i<=n;i++){
        ans = ans*2%c;
    }
    cout<<ans;

}