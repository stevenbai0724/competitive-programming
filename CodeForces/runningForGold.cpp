//
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;
        vector<vector<int>>arr(n+1, vector<int>(6));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=5;j++){
                cin>>arr[i][j];
            }
            
        }
        if(n==1){
            cout<<1<<"\n";
            continue;
        }

        int w = 1;
        vector<int>win = arr[1];

        for(int i=2;i<=n;i++){
            int pt = 0;
            for(int j=1;j<=5;j++){
                if(arr[i][j]<win[j])pt++;
            }
            if(pt>=3){
                w = i;
                win = arr[i];
            }
        }
        for(int i=1;i<=n;i++){
            if(i==w)continue;
            int pt = 0;
            for(int j=1;j<=5;j++){
                if(win[j]<arr[i][j])pt++;
            }
            if(pt<3)goto nxt;
        }
        cout<<w<<"\n";
        continue;
        nxt:;
        cout<<-1<<"\n";


    }


    return 0;
}