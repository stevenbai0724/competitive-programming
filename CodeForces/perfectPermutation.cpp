//https://codeforces.com/problemset/problem/233/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    if(n%2==1){
        cout<<-1;
        return 0;
    }
    else{
        for(int i=n;i>=1;i--){
            cout<<i<<" ";
        }
    }



    return 0;
}