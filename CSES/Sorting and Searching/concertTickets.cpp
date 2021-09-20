//https://cses.fi/problemset/task/1091
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m; cin>>n>>m;

    multiset<int>s;
    vector<int>arr(m+1);

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        s.insert(x);
    }
    s.insert(1e9);
    for(int i=1;i<=m;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=m;i++){
        int num = arr[i];

        if(s.find(num)!=s.end()){
            s.erase(s.find(num));
            cout<<num<<"\n";
        }
        else{
            auto x = s.upper_bound(num);
            if(x==s.begin() || x==s.end()) cout<<-1<<"\n";
            else{
                x--;
                cout<<*x<<"\n";
                s.erase(x);
            }
        }
    }
    
    return 0;
}