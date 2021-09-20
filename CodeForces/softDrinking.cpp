//https://codeforces.com/problemset/problem/151/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;

    int drink = (k*l)/nl;
    int limes = c*d;
    int salt = p/np;
    cout<<min(salt,(min(drink, limes)))/n;
    return 0;
}