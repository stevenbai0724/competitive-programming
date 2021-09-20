//
#include <bits/stdc++.h>
using namespace std;

#define int long long


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>arr1(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr1[i];
        }
        sort(arr1.begin(), arr1.end());

        vector<int>arr2(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr2[i];
        }
        sort(arr2.begin(),arr2.end());

        vector<int>ssa1(n+1);
        vector<int>ssa2(n+1);
        ssa1[n] = arr1[n];
        ssa2[n] = arr2[n];
        for(int i=n-1;i>=1;i--){
            ssa1[i] = arr1[i] + ssa1[i+1];
            ssa2[i] = arr2[i] + ssa2[i+1];
        }
        ssa1.push_back(0);
        ssa2.push_back(0);
        int take = n - (n/4);

        if(ssa1[n-take+1]>=ssa2[n-take+1]){
            cout<<0<<"\n";
            continue;
        }
        int cnt = 0;
        while(true){
            cnt++;
            take = n+cnt - ((n+cnt)/4);

            int team1 = ssa1[min((int)n+1, n+cnt-take+1)] + 100*cnt;
            int team2 = ssa2[max((int)1, n-take+1)];
            
            if(team1>=team2){
                cout<<cnt<<"\n";
                goto nxt;
            }


        }
        nxt:;



    }
    

    return 0;
}
