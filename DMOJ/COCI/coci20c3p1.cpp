//https://dmoj.ca/problem/coci20c3p1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    stack<int>L, R, T;

    int n; cin>>n;
    vector<int>order;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        T.push(x);
        order.push_back(x);
    }
    while(!T.empty()){
        L.push(T.top());
        T.pop();
    }

    sort(order.begin(), order.end(), [](int a, int b){
        return a > b;
    });
    vector<string>ans;

    for(int nxt=0;nxt<n;nxt++){
        bool found = false;
        while(!L.empty()){
            if(L.top() == order[nxt] && !found){
                found = true;
                ans.push_back({"UZMI D L"});
            }
            else{
                ans.push_back({"UZMI L L"});
                ans.push_back({"STAVI L D"});
                R.push(L.top());
            }
            L.pop();
        }
        ans.push_back({"STAVI D L"});
        while(!R.empty()){
            ans.push_back({"UZMI L D"});
            ans.push_back({"STAVI L L"});
            L.push(R.top());
            R.pop();
        }
    }
    cout<<ans.size()<<"\n";
    for(string s: ans)cout<<s<<"\n";

    return 0;
}