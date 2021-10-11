//https://codeforces.com/contest/1579/problem/D
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        set<pair<int,int>>s;
        vector<int>arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            if(arr[i]!=0)s.insert({arr[i],i});
        }
        vector<pair<int, int>>ans;
        while(s.size()>1){
            auto it1 = s.end(); it1--;
            auto it2 = s.end(); it2--; it2--;
            pair<int, int> a = *it1;
            pair<int, int> b = *it2;

            ans.push_back({a.second, b.second});
            a.first--;
            b.first--;

            s.erase(it1);
            s.erase(it2);

            if(a.first>0)s.insert(a);
            if(b.first>0)s.insert(b);
        }
        cout<<ans.size()<<"\n";
        for(auto p: ans){
            cout<<p.first<<" "<<p.second<<"\n";
        }





    }


    return 0;
}