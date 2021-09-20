//https://dmoj.ca/problem/cco96p1
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int count = 0;
        while(true){
            bool sort = true;
            for(int i=0;i<n-1;i++){
                if(arr[i]>arr[i+1]){
                    count++;
                    int temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                    sort = false;
                }
            }
            if(sort)break;

        }
        cout<<"Optimal train swapping takes "<<count<<" swaps.\n";

    }

}