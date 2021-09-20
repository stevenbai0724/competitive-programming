//https://codeforces.com/problemset/problem/155/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    
    int mx, mn;
    int count = 0;
    cin>>mx;
    mn = mx;

    for(int i=1;i<n;i++){
        int x; cin>>x;
        if(x>mx){
            count++;
            mx = x;
        }
        else if (x<mn){
            count++;
            mn = x;
        }
    }
    cout<<count;
    

    return 0;
}