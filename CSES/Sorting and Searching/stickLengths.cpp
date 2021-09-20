//https://cses.fi/problemset/task/1074
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    if(n==1){
        cout<<0<<"\n";
        return 0;
    }
    if(n==2){
        cout<<abs(arr[1]-arr[2])<<"\n";
        return 0;
    }
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    sort(arr.begin(), arr.end());
    for(int i=1;i<=n;i++){
        count1+=abs(arr[i]-arr[n/2]);
        count2+=abs(arr[i]-arr[n/2+1]);
        count3+=abs(arr[i]-arr[n/2-1]);
    }
    cout<<min(count1, min(count2, count3))<<"\n";


    return 0;
}