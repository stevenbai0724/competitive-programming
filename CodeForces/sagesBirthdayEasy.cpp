//https://codeforces.com/problemset/problem/1419/D1
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
    sort(arr.begin(), arr.end());

    if(n<3){
        cout<<"0\n";
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return 0;
    }

    queue<int>big, small;

    for(int i=1;i<=n;i++){
        small.push(arr[i]);
        big.push(arr[n-i+1]);
    }

    vector<int>ans;
    ans.push_back(0);

    for(int i=1;i<=n;i++){
        if(i&1){
            ans.push_back(big.front());
            big.pop();
        }
        else{
            ans.push_back(small.front());
            small.pop();
        }
    }
    int cnt = 0;
    for(int i =2;i<n;i++){
        if(ans[i]<ans[i-1] && ans[i]<ans[i+1])cnt++;
    }
    cout<<cnt<<"\n";
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";


    return 0;
}