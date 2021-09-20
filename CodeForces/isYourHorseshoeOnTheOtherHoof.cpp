//https://codeforces.com/problemset/problem/228/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    set<int>s;

    for(int i=1;i<=4;i++){
        int x; cin>>x;
        s.insert(x);
    }
    cout<<4-s.size();

    return 0;
}