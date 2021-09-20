//https://codeforces.com/problemset/problem/1006/C
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    vector<int>psa, ssa;
    psa.push_back(0);
    ssa.push_back(0);

    int sum = 0;
    for(int i=1;i<=n;i++){
        sum+=arr[i];
        psa.push_back(sum);
    }
    sum = 0;
    for(int i=n;i>=1;i--){
        sum+=arr[i];
        ssa.push_back(sum);
    }
    int mx = 0;
    for(int i=1;i<=n;i++){

        auto it = lower_bound(ssa.begin(), ssa.end(), psa[i]);
        
        if(*it==psa[i]){
            if((it-ssa.begin()) + i <=n ){
                mx = psa[i];
            }
        }

    }
    cout<<mx<<"\n";

    return 0;
}


/*
Two pointer solution
//https://codeforces.com/problemset/problem/1006/C
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    int r = n;

    int lSum = 0;
    int rSum = arr[r];
    int mx = 0;

    for(int i=1;i<n;i++){
        lSum+=arr[i];

        while(rSum<lSum && r-1>i){
            r--;
            rSum+=arr[r];
        }
        if(lSum==rSum)mx = lSum;

    }
    cout<<mx<<"\n";


    return 0;
}
*/