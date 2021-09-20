//https://codeforces.com/problemset/problem/1320/A
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<pair<int, int>>arr(n+1);
    arr[0] = {-1e18, -1e18};
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        arr[i] = {x-i,x};
    }
    sort(arr.begin(), arr.end());

    int mx = 0;

    for(int i=1;i<=n;i++){
        int j = i;
        int sum = arr[j].second;

        while(j<n && arr[j+1].first==arr[j].first){
            j++;
            sum += arr[j].second;
        }
        i = j;
        mx = max(mx, sum);
    }
    cout<<mx<<"\n";


    return 0;
}