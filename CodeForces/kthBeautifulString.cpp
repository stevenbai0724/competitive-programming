//
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);


    vector<int>arr;
    arr.push_back(0);
    for(int i=1;i<=64000;i++){
        arr.push_back((i)*(i+1)/2 - (i-1));
    }

    int t; cin>>t;
    while(t--){
        
        int n, k;
        cin>>n>>k;

        string s = "";
        for(int i=1;i<=n;i++){
            s+='a';
        }

        auto it = upper_bound(arr.begin(), arr.end(), k);
        it--;

        int l = it-arr.begin();

        s[n-1-l] = 'b';
        
        int r = k-*it;
        s[n-1-r] = 'b';

        cout<<s<<"\n";


    }


    return 0;
}