//https://cses.fi/problemset/task/1629
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<pair<int, int>>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].second>>arr[i].first;
    }
    sort(arr.begin(), arr.end());
    int cur = 0;    
    int ans = 0;
    for(auto p: arr){
        int start = p.second;
        int end = p.first;
        if(start>=cur){
            cur = end;
            ans++;
        }
    }
    cout<<ans<<"\n";


    return 0;
}