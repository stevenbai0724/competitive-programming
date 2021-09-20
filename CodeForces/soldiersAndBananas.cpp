//https://codeforces.com/problemset/problem/546/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    
    int k,n,w;
    cin>>k>>n>>w;

    int cost = 0;

    for(int i =1;i<=w;i++){
        cost+= (k*i);
    }
    if(cost-n>0)cout<<cost-n;
    else cout<<0;

    return 0;
}