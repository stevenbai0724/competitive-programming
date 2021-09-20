//
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int k, n, m;
        cin>>k>>n>>m;

        queue<int>a;
        queue<int>b;
        for(int i=1;i<=n;i++){
            int x; cin>>x;
            a.push(x);
        }
        for(int i=1;i<=m;i++){
            int x; cin>>x;
            b.push(x);
        }
        vector<int>ans;

        for(int i=1;i<=n+m && !(a.empty() && b.empty());i++){
            int curA;
            int curB;
            if(a.empty()){
                curA = 1e18;
            }
            else curA = a.front();

            if(b.empty()){
                curB = 1e18;     
            }
            else curB = b.front();

            if(curA<curB || curB==1e18){
                if(curA == 0){
                    k++;
                    a.pop();
                    ans.push_back(0);
                }
                else if(curA<=k){
                    a.pop();
                    ans.push_back(curA);
                }
                else{
                    cout<<"-1\n";
                    goto nxt;
                }
            }
            else if(curB<=curA || curA == 1e18){
                if(curB == 0){
                    k++;
                    b.pop();
                    ans.push_back(0);
                }
                else if(curB<=k){
                    b.pop();
                    ans.push_back(curB);
                }
                else{
                    cout<<"-1\n";
                    goto nxt;
                }
            }
        }
        for(auto x: ans){
            cout<<x<<" ";
        }
        cout<<"\n";
        nxt:;



    }


    return 0;
}