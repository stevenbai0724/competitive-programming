//https://codeforces.com/problemset/problem/158/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;
    vector<int>arr(n+1);
    int ans = 0;
    int num = 0;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(i==k)num = arr[i];
    }

    for(int i=1;i<=n;i++){
        if(arr[i]!=0 && arr[i]>=num)ans++;
    }
    cout<<ans;
  
    return 0;
}