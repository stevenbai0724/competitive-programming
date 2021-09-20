#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int sum = 0;
    int n; cin>>n;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        sum+=x;

        arr[i] = sum;
    }


    int q; cin>>q;
    while(q--){
        int num; cin>>num;

        int l = 0;
        int r = n;

        while(l+1<r){
            int m = (l+r)/2;

            if(arr[m]>=num)r = m;
            else l = m;

        }
        cout<<r<<"\n";

    }

    return 0;
}