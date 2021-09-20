//https://codeforces.com/problemset/problem/1535/B
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool comp(int a, int b){
    return a>b;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    

    int t; cin>>t;

    vector<int>ans;
    ans.push_back(0);

    for(int i=1;i<=72;i++){
        ans.push_back(i*i);
    }
    while(t--){
        
        int n; cin>>n;

        cout<<lower_bound(ans.begin(), ans.end(), n)-ans.begin()<<"\n";





    }


    return 0;
}