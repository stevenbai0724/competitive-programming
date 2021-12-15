#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);


    int a, b, c;
    cin >> a >> b>>c;
    bool yes = true;

    if(a+b<=c) yes = false;
    if(a+c<=b) yes = false;
    if(b+c<=a) yes = false;

    if(yes) cout<<"yes";
    else cout<<"no";
    return 0;
}