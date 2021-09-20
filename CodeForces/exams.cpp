//https://codeforces.com/problemset/problem/479/C
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<pair<int, int>>arr;

    for(int i=1;i<=n;i++){
        int x, y;
        cin>>x>>y;
        arr.push_back({x,y});
    }
    sort(arr.begin(), arr.end());

    int ans = min(arr[0].second, arr[0].first);

    for(int i=1;i<arr.size();i++){
        if(arr[i].second<ans){
            ans = arr[i].first;
        }
        else{
            ans = min(arr[i].first, arr[i].second);
        }
    }
    cout<<ans<<"\n";

    return 0;
}