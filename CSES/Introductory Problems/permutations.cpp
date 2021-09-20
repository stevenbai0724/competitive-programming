#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin>>n;
    
    if(n==1){
        cout<<1;
        return 0;
    }
    if(n==4){
        cout<<2<<" "<<4<<" "<<1<<" "<<3;
        return 0;
    }
    if(n==2 || n ==3){
        cout<<"NO SOLUTION";
    }
    else{
        int num = n;
      
        while(num>0){
            cout<<num<<" ";
            num-=2;
            
        }   
        num = n-1;
        while(num>0){
            cout<<num<<" ";
            num-=2;
        }
    }
    return 0;
}