//https://codeforces.com/problemset/problem/1561/C
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int n; cin>>n;

        vector<vector<int>>arr(n+1);
        vector<pair<int, int>>req;
        
        for(int i=1;i<=n;i++){
            int m; cin>>m;
            vector<int>temp(m+1);
            for(int j=1;j<=m;j++){
                cin>>temp[j];
            }
            
            arr[i] = temp;

            int mx = 0;

            int diff = 1;

            for(int j=1;j<=m;j++){
                mx = max(mx, temp[j]+diff);
                diff--;
            }

            req.push_back({mx, i});

        }
        sort(req.begin(), req.end());


        int l = 1;
        int r = 1e9+4;

        while(l+1<r){
            int m = (l+r)/2;
            bool good = true;
            int pts = m;

            for(auto p: req){
                if(p.first<=pts){
                    pts += arr[p.second].size()-1;
                }
                else{
                    good = false;
                    break;
                }
            }
            if(good)r = m;
            else l = m;

        }
        cout<<r<<"\n";
   

    }


    return 0;
}