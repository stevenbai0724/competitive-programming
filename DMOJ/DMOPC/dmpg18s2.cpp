//https://dmoj.ca/problem/dmpg18s2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1);
    vector<int>psa(n+1);
    int sum = 0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        psa[i] = psa[i-1];
        psa[i] += arr[i];
    }

    vector<int>ans{0};
    int L = 0;
    int R = n;
    for(int i=1;i<=(n+1)/2;i++){
        sum += psa[R]-psa[L];
        R--;
        L++;
        ans.push_back(sum);
    }
    int m = ans.size();

    for(int i=1;i<m;i++){
        cout<<ans[i]<<"\n";
    }

    for(int i=(n)/2;i>=1;i--){
        cout<<ans[i]<<"\n";
    }

    return 0;
}