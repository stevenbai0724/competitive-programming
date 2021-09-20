//https://codeforces.com/problemset/problem/50/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; 
    cin>>n>>m;
    if(n==1 && m==1){
        cout<<0;
        return 0;
    }
    cout<<(max(n,m)/2)*(min(n,m)) + (min(n,m)/2)*(max(n,m)%2);
    return 0;
}