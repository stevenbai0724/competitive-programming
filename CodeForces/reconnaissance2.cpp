//https://codeforces.com/problemset/problem/34/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<int>arr(n+1);
    for(int i =1;i<=n;i++){
        cin>>arr[i];
    }
    int ans = abs(arr[n] - arr[1]);
    int l = 1;
    int r = n;

    for(int i=1;i<n;i++){
        if(abs(arr[i]- arr[i+1])<ans){
            ans = abs(arr[i]-arr[i+1]);
            l = i;
            r = i+1;
        }
    }
    cout<<l<<" "<<r;
    
    return 0;
}