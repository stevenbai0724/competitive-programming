#include <bits/stdc++.h>
using namespace std;
#define int long long

int sign(int x){
    if(x<0)return -1;
    else return 1;
}
signed main(){

    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        vector<int>arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        int sum = 0;
        for(int i=1;i<=n;i++){
            int j = i;
            int cur = arr[i];
            

            while(j<=n && (sign(arr[j]) == sign(arr[i]))){
                cur = max(cur, arr[j]);
                j++;
            }
            i = j-1;
            sum+=cur;
        }
        cout<<sum<<"\n";

    }

    return 0;
}