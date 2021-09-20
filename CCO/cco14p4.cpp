#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, p;
    cin>>n>>p;
    vector<pair<int,int>>arr;
    int fuel = 0;
    int count = 1;
    for(int i=1;i<=n;i++){
        int a, b;
        cin>>a>>b;
        if(i==p){
            fuel = a;
            continue;
        }
        arr.push_back({b,a});
    }
    sort(arr.begin(), arr.end());
    for(int i=0;i<n-1;i++){
        int a = arr[i].second;
        int b = arr[i].first;
        if(a>=b && b<=fuel){
            fuel += a-b;
            count++;
        }
    }
    cout<<fuel<<"\n"<<count;

    return 0;
}