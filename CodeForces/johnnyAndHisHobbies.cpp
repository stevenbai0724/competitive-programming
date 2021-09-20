//https://codeforces.com/problemset/problem/1362/B
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;

        vector<int>arr(n+1);

        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());

        for(int i=1;i<=1024;i++){
            vector<int>temp = arr;
            for(int j=1;j<=n;j++){
                temp[j] ^= i;
            }
            sort(temp.begin(), temp.end());

            if(temp==arr){
                cout<<i<<"\n";
                goto nxt;
            }
        }
        cout<<-1<<"\n";
        nxt:;
    }

    return 0;
}