//https://codeforces.com/problemset/problem/47/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<bool>arr(501, false);

    for(int i=1;(i*(i+1))/2<=500;i++){
        arr[(i*(i+1))/2] = true;
    }
    if(arr[n])cout<<"YES";
    else cout<<"NO";



    return 0;
}
