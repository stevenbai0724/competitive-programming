//https://codeforces.com/problemset/problem/200/B
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    double sum = 0;

    for(int i=1;i<=n;i++){
        double x; cin>>x;
        sum+=x;
    }
    cout<<sum/n;
    


    return 0;
}