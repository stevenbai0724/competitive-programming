//https://codeforces.com/contest/1360/problem/D
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int ans = n;

        //i is shovels/pack 
        for(int i =1;i*i<=n;i++){
            if(n%i==0){
                if(n/i<=k){
                    ans= min(ans, i);
                }
                if(i<=k){
                    ans =min(ans, n/i);
                }
            }
        }
        cout<<ans<<"\n";

    }
    return 0;
}