//https://codeforces.com/problemset/problem/181/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<int>x(104);
    vector<int>y(104);

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            if(s[j-1]=='*'){
                x[i]++;
                y[j]++;
            }
        }
    }
    for(int i =1;i<=100;i++){
        if(x[i]==1)cout<<i<<" ";
    }
    for(int i=1;i<=100;i++){
        if(y[i]==1)cout<<i;
    }
    return 0;
}