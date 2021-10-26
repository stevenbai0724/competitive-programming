//https://cses.fi/problemset/task/1645
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    stack<pair<int, int>>s;


    for(int i=1;i<=n;i++){

        if(s.empty()){
            cout<<"0 ";
            s.push({arr[i],i});
            continue;

        }

        while(!s.empty()){
            if(s.top().first<arr[i]){
                cout<<s.top().second<<" ";
                s.push({arr[i],i});
                goto nxt;
            }
            s.pop();
        }

        cout<<"0 ";
        s.push({arr[i], i});

        nxt:;


    }
    cout<<"\n";

    return 0;
}