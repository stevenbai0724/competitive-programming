//https://codeforces.com/problemset/problem/1140/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1);
    int mx = 0;
    int count = 0;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i =1;i<=n;i++){
        mx = max(mx, arr[i]);

        if(mx == i){
            count++;
            mx = 0;
        }
    }
    cout<<count;

    
    return 0;
}