//https://cses.fi/problemset/task/1640
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int c = 1e10+7;
    int n, x;
    cin>>n>>x;
    vector<int>arr(n+1); //divide c to get value, mod c to get position
    for(int i=1;i<=n;i++){
        int num; cin>>num;
        arr[i] = num*c + i;
    }
    sort(arr.begin(), arr.end());
    int l = 1;
    int r = n;
    while(l<r){
        

        if(arr[l]/c + arr[r]/c <x) l++;
        else if(arr[l]/c + arr[r]/c >x)r--;
        else{
            cout<<arr[l]%c<<" "<<arr[r]%c;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}