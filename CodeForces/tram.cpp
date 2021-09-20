//https://codeforces.com/problemset/problem/116/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    int ans = 0;
    int sum = 0;
    for(int i=1;i<=n;i++){
        int a,b; cin>>a>>b;
        sum -=a;
        sum +=b;
        ans = max(sum, ans);

    }
    cout<<ans;
    return 0;
}
