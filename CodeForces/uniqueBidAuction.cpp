//https://codeforces.com/contest/1454/problem/B
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

   
    int t; cin>>t;

    for(t; t>0;t--){
        int n; cin>>n;
        int ans = 10000000;
        vector<int>arr(n+1);
        vector<int>pos(n+1);
        for(int i =1;i<=n;i++){
            int x; cin>>x;
            arr[x]++;
            pos[i] = x;
        }
        for(int i =1;i<=n;i++){
            if(arr[i]==1) ans = min(ans, i);
        }

        if(ans==10000000) cout<<-1<<"\n";
        else{
            for(int i=1;i<=n;i++){
                if(pos[i]==ans){
                    cout<<i<<"\n";
                    break;
                }
            }
        }

        
    }
    return 0;
}