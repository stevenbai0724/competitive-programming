//https://codeforces.com/problemset/problem/1443/B
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int a, b; //detonate, place
        cin>>a>>b;

        string s; cin>>s;
        int n = s.length();

        vector<pair<int,int>>segs;

        for(int i=0;i<n;i++){   
            if(s[i]=='1'){
                int j = i;
                while(j<n-1 && s[j+1]==1)j++;
                segs.push_back({i,j});
                i = j;
            }
        }
        if(segs.size()==0){
            cout<<"0\n";
            continue;
        }
        int ans = a;

        for(int i=1;i<segs.size();i++){
            int l1 = segs[i-1].first;
            int r1 = segs[i-1].second;
            int l2 = segs[i].first;
            int r2 = segs[i].second;

            ans += min((l2-r1-1)*b, a);
        }
        cout<<ans<<"\n";


    }

    return 0;
}