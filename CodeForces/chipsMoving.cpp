//https://codeforces.com/contest/1213/problem/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int e, o;
    e = 0;
    o = 0;
    for(n;n>0;n--){
        int x; cin>>x;
        if(x%2==0) e++;
        else o++;

    }
    cout<<min(e,o);

    return 0;
}