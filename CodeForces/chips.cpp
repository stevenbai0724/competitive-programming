//https://codeforces.com/problemset/problem/92/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin>>n>>m;
    int count = 1;
    while(true){
        if(count==n+1)count = 1;
        if(m-count<0)break; 
        m-=count;
        count++;
       
    }
    cout<<m;
    return 0;
}