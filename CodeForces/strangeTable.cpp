//https://codeforces.com/problemset/problem/1506/A
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n, m, x;
        cin>>n>>m>>x;

        
        int r = x%n;
        if(r==0)r = n;
        int c = (x-1)/n +1;


        cout<<(m*(r-1)) + c<<"\n";




    }


    return 0;
}