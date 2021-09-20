#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);


    int n; cin>>n;
    vector<int>arr(n+1);
    int count = 0;
    for(int i =1;i<=n;i++){
        cin>>arr[i];    
    }

    for(int i=2;i<=n;i++){
        if(arr[i]<arr[i-1]){
            count += arr[i-1]-arr[i];
            arr[i] = arr[i-1];
        }
    } 
    cout<<count;


    return 0;
}