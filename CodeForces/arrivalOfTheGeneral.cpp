//https://codeforces.com/problemset/problem/144/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    int mx = 0;
    int mn = 1e9;
    int mxIndex=  0;
    int mnIndex = 0;
    int ans = 0;
    for(int i =1;i<=n;i++){
        int x; cin>>x;
        if(x>mx){
            mx = x;
            mxIndex = i;
        }
        if(x<=mn){
            mn =x;
            mnIndex = i;
        }
    }
    if(mxIndex <mnIndex) cout<<(mxIndex-1)+(n-mnIndex);
    else cout<<(mxIndex-1)+(n-mnIndex) -1;



    return 0;
}