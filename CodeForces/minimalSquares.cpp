//https://codeforces.com/contest/1360/problem/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    for(int i =1;i<=t;i++){
        int a, b;
        cin>>a>>b;

        cout<<max(max(a,b), min(a, b)*2)*max(max(a,b), min(a, b)*2)<<"\n";
    }

    return 0;
}