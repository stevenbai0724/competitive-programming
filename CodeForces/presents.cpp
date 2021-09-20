//https://codeforces.com/problemset/problem/136/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1);

    for(int i =1;i<=n;i++){
        int x; cin>>x;
        arr[x] = i;
    }for(int i =1;i<=n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}