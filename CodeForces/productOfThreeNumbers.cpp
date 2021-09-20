//https://codeforces.com/problemset/problem/1294/C
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;
        int OG = n;

        int first = 0;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                first = i;
                break;
            }
        }
        if(first==0){
            cout<<"NO\n";
            continue;
        }
        n/=first;

        int second = 0;
        for(int i=2;i*i<=n;i++){
            if(n%i==0 && i!=first){
                second = i;
                break;
            }
        }
        if(second==0){
            cout<<"NO\n";
            continue;
        }
        n/=second;

        int third = OG/(first*second);

        if(third==1 || third ==first || third == second || (first*second*third)!=OG)cout<<"NO\n";
        else cout<<"YES\n"<<first<<" "<<second<<" "<<third<<"\n";


        



    }


    return 0;
}