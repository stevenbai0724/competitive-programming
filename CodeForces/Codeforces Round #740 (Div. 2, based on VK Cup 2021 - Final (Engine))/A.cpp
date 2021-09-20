//https://codeforces.com/contest/1561/problem/A
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int n; cin>>n;

        vector<int>arr(n+1);

        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        vector<int>sorted = arr;
        sort(sorted.begin(), sorted.end());

        int cnt = 0;

        while(true){
            if(arr == sorted)break;
            cnt++;
            if(cnt&1){
                for(int i=1;i<n;i+=2){
                    if(arr[i]>arr[i+1]){
                        int temp = arr[i];
                        arr[i] = arr[i+1];
                        arr[i+1] = temp;
                    }

                }
            }
            else {
                for(int i=2;i<n;i+=2){
                    if(arr[i]>arr[i+1]){
                        int temp = arr[i];
                        arr[i] = arr[i+1];
                        arr[i+1] = temp;
                    }
                    
                }
            }
            if(arr == sorted)break;

        }
        cout<<cnt<<"\n";
       
    }


    return 0;
}