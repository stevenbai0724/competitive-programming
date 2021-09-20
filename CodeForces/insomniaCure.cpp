//https://codeforces.com/problemset/problem/148/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int k,l,m,n,d;
    cin>>k>>l>>m>>n>>d;
    int count = 0;

    for(int i=1;i<=d;i++){
        if(i%k==0) count++;
        else if (i%l==0) count++;
        else if (i%m==0) count++;
        else if (i%n==0) count++;
    }
    cout<<count;


}