//https://codeforces.com/problemset/problem/1399/A
//check if any 2 numbers have a difference greater than 1 (after sorted)
//If difference is greater than one, the 2 numbers will never be removed
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    for(t;t>0;t--){
        int n; cin>>n;
        vector<int>arr(n+1);

        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());

        bool found = true;
        for(int i=1;i<n;i++){
            if(arr[i+1]-arr[i]>1){
                found = false;
                break;
            }
        }
        if(found)cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";



    }

    return 0;
}