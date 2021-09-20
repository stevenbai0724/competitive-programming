#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin>>t;
    while(t--){
        int n, k; 
        cin>>n>>k;

        vector<int>arr(n+1);

        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        int i = 1;
        while(i<n && k>0){

            int sub = min(k, arr[i]);
            arr[i] -= sub;

            arr[n] += sub;

            k-=sub;

            i++;
        }
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";


    }
    return 0;
}