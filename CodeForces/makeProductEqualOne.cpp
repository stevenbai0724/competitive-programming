//https://codeforces.com/contest/1206/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;cin>>n;
    int count = 0;
    int negCount = 0;
    int zeroCount = 0;


    for(int i=1;i<=n;i++){
        int x; cin>>x;

        if(x>1)count+=(x-1);
        if(x<=-1){
            count+=(-1-x);
            negCount++;
        }
        if(x==0){
            zeroCount++;
        }
    }
    if(zeroCount==0){
        if(negCount%2==0){
            cout<<count;
            return 0;
        }
        else{
            cout<<count+2;
            return 0;
        }
    }
    else{
        cout<<count+ (zeroCount);
    }
   
    
    




    return 0;
}