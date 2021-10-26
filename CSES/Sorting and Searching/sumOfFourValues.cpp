//https://cses.fi/problemset/task/1642
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, x;
    cin>>n>>x;

    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    map<int, pair<int, int>>mp;

    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            mp[arr[i] + arr[j]] = {i,j};
        }
    }

    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int val = arr[i] + arr[j];
            int comp = x - val;

            if(mp[comp].first!=0){
                int ind1 = mp[comp].first;
                int ind2 = mp[comp].second;
                set<int>temp;
                temp.insert(i);
                temp.insert(j);
                temp.insert(ind1);
                temp.insert(ind2);
                if(temp.size()==4){
                    for(int num : temp)cout<<num<<" ";
                    cout<<"\n";
                    return 0;
                }

            }
        }
    }
    cout<<"IMPOSSIBLE\n";




    return 0;
}