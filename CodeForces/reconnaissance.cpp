//https://codeforces.com/problemset/problem/32/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, d;
    cin>>n>>d;
    int sum = 0;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i =1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(abs(arr[i]-arr[j])<=d)sum++;
        }
    }
    cout<<sum*2;


    return 0;
}