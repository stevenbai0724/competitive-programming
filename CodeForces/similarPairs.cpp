//https://codeforces.com/contest/1360/problem/C
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    for(t;t>0;t--){
        int n; cin>>n;
        int o = 0;
        int e = 0;
        vector<int>arr(n+1);

        for(int i =1;i<=n;i++){
            cin>>arr[i];
            if(arr[i]%2==0) e++;
            else o++;
        }
        sort(arr.begin(), arr.end());
        if(e%2==0 && o%2==0){
            cout<<"YES"<<"\n";
            continue;
        }
        else{
            bool found = false;
            for(int i =1;i<n;i++){
                if((arr[i+1] - arr[i]) ==1){
                    found = true;
                    break;
                }
            }
            if(found)cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }

    }

    return 0;
}