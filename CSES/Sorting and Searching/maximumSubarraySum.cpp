//https://cses.fi/problemset/task/1643
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int best = -1e18, sum = 0;
    for (int k = 0; k < n; k++) {
        
        //2 cases, we take the current element as the subarray or add it to the subarray
        sum = max(array[k],sum+array[k]); 
        best = max(best,sum); //take the best sum
    }
    cout << best << "\n";

    return 0;
}