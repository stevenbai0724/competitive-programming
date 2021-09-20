//https://codeforces.com/problemset/problem/1426/A
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;


        if(n==1 || n==2){
            cout<<1<<"\n";
            continue;
        }

        vector<int>ans;


        for(int i=1;i<=2000;i++){
            ans.push_back((i*x)+2);
        }

        cout<<lower_bound(ans.begin(), ans.end(), n)-ans.begin()+2<<"\n";


    }



    return 0;
}