//https://codeforces.com/contest/1438/problem/B
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    for(t; t>0;t--){

        int n; cin>>n;
        vector<int>arr(n+1);
        int sum = 0;
        bool found = false;

        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());

        for(int i =1;i<n;i++){
            if(arr[i] == arr[i+1]) found = true;
        }
        if(found) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";



    }

    return 0;
}