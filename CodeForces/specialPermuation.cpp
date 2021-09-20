//https://codeforces.com/contest/1454/problem/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

   
    int t; cin>>t;

    for(t; t>0;t--){
        int n; cin>>n;


        if(n%2==0){
            for(int i =n;i>=1;i--){
                cout<<i<<" ";
            }
        }
        else{
            
            for(int i =n;i>=1;i--){
                if(i == (n-(n/2))){
                    cout<<i-1<<" ";
                }
                else if(i == n/2){
                    cout<<i+1<<" ";
                }
                else cout<<i<<" ";
            }


        }
        cout<<"\n";
    }




    return 0;
}