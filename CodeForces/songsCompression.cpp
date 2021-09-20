//https://codeforces.com/problemset/problem/1015/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m; cin>>n>>m;
    int sum = 0;
    int count  =0;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        int s, c;
        cin>>s>>c;
        sum+=s;
        arr[i] = s-c;
    }
    sort(arr.begin(), arr.end(), greater<int>());

    for(int i=0;i<n;i++){
        if(sum<=m){
            cout<<count;
            return 0;
        }
        else{
            sum-=arr[i];
            count++;
        }
    }
    if(sum<=m){
        cout<<count;
        return 0;
    }
    cout<<-1;
    return 0;
}