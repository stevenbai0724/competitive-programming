//https://codeforces.com/problemset/problem/214/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    int count = 0;

    for(int a=0;a<=max(n,m);a++){
        for(int b=0;b<=max(n,m);b++){

            if(a*a+b==n && b*b+a==m)count++;
        }
    }
    cout<<count;
    

    return 0;
}