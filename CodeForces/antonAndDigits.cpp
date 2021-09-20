//https://codeforces.com/problemset/problem/734/B
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int k2, k3, k5, k6;
    cin>>k2>>k3>>k5>>k6;
    int sum = 0;
    int mn = min(k2, min(k5, k6));

    sum += 256*mn;
    sum += 32* min(k3, k2-mn);

    cout<<sum;

    
    return 0;
}