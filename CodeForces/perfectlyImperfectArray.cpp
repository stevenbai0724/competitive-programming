#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int n; cin>>n;

        vector<int>arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<=n;i++){
            double rt = sqrt(arr[i]);
            if(!(trunc(rt)==rt)){
                cout<<"YES\n";
                goto nxt;
            }

        }
        cout<<"NO\n";

        nxt:;
    }


    return 0;
}