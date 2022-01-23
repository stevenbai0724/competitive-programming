#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    while(true){
        int n; cin>>n;
        if(n==0)break;

        vector<int>arr(n+1);
        vector<int>diff(n+1);

        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<n;i++){
            diff[i] = arr[i+1] - arr[i];
        }
        if(n == 1){
            cout<<0<<"\n";
            continue;
        }
        if(n == 2){
            cout<<1<<"\n";
            continue;
        }
        int ans = n-1;

        for(int t=1;t<n-1;t++){
            bool good = true;

            for(int i=1;i<n;i++){
                if(i - t >=1){
                    if(diff[i] != diff[i-t])good = false;
                }
            }
            if(good){
                ans = t;
                break;
            }
        }
        cout<<ans<<"\n";

    }


    return 0;
}