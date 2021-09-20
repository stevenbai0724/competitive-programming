//https://codeforces.com/problemset/problem/1334/B
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){

        int n, x;
        cin>>n>>x;

        vector<int>arr(n+1);
        vector<int>psa(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

        sort(arr.begin(), arr.end());

      
        for(int i=1;i<=n;i++){
            psa[i] = arr[i] + psa[i-1];
        }

        for(int i=0;i<n;i++){
            int sum = psa[n]-psa[i];

            double num = (n-i);

            if(sum/num >= x){
                cout<<(int)num<<"\n";
                goto nxt;
            }

        }
        cout<<0<<"\n";
        nxt:;     
    }

    return 0;   
}