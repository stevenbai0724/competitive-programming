#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m; cin>>n>>m;
    int x = m/n;
    int count = 0;
    

    if(m%n==0){
        while(x%2 ==0){
            x/=2;
            count++;
        }
        while(x%3 ==0){
            x/=3;
            count++;
        }
        if(x!=1) cout<<-1;
        else cout<<count;
        return 0;
    }
    cout<<-1;
    return 0;
}