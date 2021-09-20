//https://codeforces.com/problemset/problem/1492/B
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;
        vector<int>arr(n+1);
        vector<int>ind(n+1);
        multiset<int>left;

        for(int i=1;i<=n;i++){
            cin>>arr[i];
            ind[arr[i]] = i;
            left.insert(arr[i]);
        }
        int mx = n;
        int r = n+1;
        int l = ind[mx];
        vector<int>ans;

        while(true){
            
            for(int i=l;i<r;i++){
                ans.push_back(arr[i]);
                left.erase(left.find(arr[i]));
                
            }
            
            if(ans.size()==n)break;
            r = ind[mx];

            auto it = left.rbegin();  
            mx = *it;

            l = ind[mx];

        }
        
            
        
        for(int x: ans)cout<<x<<" ";
        cout<<"\n";

    }


    return 0;
}