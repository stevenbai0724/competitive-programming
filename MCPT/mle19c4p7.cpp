#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define double long double

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<int>power(n+2);
    power[0] = 1;


    string s; cin>>s;

    int b, p;
    cin>>b>>p;

    for(int i=1;i<=n+1;i++){
        power[i] = power[i-1] * b;
        power[i] %= p;
    }
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum += ((int)s[i] * power[i])%p;
    }

    cout<<sum%p<<"\n";



    return 0;
}