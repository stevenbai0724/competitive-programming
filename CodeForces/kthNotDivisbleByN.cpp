#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    for(t;t>0;t--){
        int n,k;
        cin>>n>>k;

        cout<<k+((k-1)/(n-1))<<"\n";
    }
    return 0;
}