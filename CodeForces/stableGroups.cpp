//https://codeforces.com/problemset/problem/1539/C
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k, x;
    cin>>n>>k>>x;

    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());

    vector<int>gaps;

    for(int i=1;i<n;i++){
        if(arr[i]+x<arr[i+1]){
            gaps.push_back(arr[i+1]-arr[i]-1);
        }
    }
    sort(gaps.begin(), gaps.end());


    int segments = gaps.size()+1;
    for(int g: gaps){
        int cost = g/x;
        if(cost<=k){
            k-=cost;
            segments--;
        }
        else break;
    }
    cout<<segments<<"\n";



    return 0;
}