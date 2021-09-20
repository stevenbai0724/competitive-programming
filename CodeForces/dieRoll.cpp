//https://codeforces.com/problemset/problem/9/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    int ans = 7- max(n, m);
    int big = 6;
    if(ans==0){
        cout<<"0/1";
        return 0;
    }
    for(int i=2;i<=6;i++){
        while(!(ans%i) && !(big%i)){
            ans/=i;
            big/=i;
        }
    }
    cout<<ans<<"/"<<big;


    return 0;
}