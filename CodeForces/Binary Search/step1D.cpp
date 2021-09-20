#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+2);
    arr[0] = -(int)1e18;
    arr[n+1] = (int)1e18;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr.begin()+1, arr.begin()+n+1);
    int k; cin>>k;

    for(int i=1;i<=k;i++){
        int left, right;
        int x, y;
        cin>>x>>y;

        int l = 0, r = n+1;

        //closest on left
        while(l+1<r){
            int m = (l+r)/2;

            if(arr[m]<x) l=m;
            else r =m;
        }
        left = l;
        l = 0; r = n+1;
        //closest on right
        while(l+1<r){
            int m =(l+r)/2;

            if(arr[m]<=y)l = m;
            else r =m;
        }
        right =r;
        cout<<right-left-1<<" ";
    }



    return 0;
}