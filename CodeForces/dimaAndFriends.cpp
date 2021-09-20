//https://codeforces.com/problemset/problem/272/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;
    int sum = 0;
    int ans = 0;
    for(int i =1;i<=n;i++){
        int x; cin>>x;
        sum+=x;
    }
    for(int i =1;i<=5;i++){
        if((i+sum)%(n+1)!=1)ans++;
    }
    cout<<ans;
    return 0;
}