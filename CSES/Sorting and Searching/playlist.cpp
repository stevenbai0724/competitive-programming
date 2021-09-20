//https://cses.fi/problemset/task/1141
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n; 

    map<int, int>last;
    int skip = 0;
    int ans = 0;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        skip = max(skip, last[x]);
        ans = max(ans, i-skip);
        last[x] = i;
    }
    cout<<ans;

}