//https://codeforces.com/problemset/problem/620/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<max(abs(x1-x2), abs(y1-y2));

    return 0;
}