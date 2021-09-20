#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int n, m;
        cin>>n>>m;

        vector<vector<int>>arr(n+1, vector<int>(m+1));
        vector<int>mn;
        queue<int>q;
        vector<vector<int>>mark(n+1, vector<int>(m+1));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>arr[i][j];
                mn.push_back(arr[i][j]);
            }
            sort(arr[i].begin(), arr[i].end());

        }
        sort(mn.begin(), mn.end());
        
        for(int i=0;i<m;i++){
            q.push(mn[i]);
        }
        vector<int>cols(m+1);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(!mark[i][j] && arr[i][j]==cur){
                        mark[i][j] = 1;
                        cols[j]++;
                        goto nxt;
                    }
                }
            }
            nxt:;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mark[i][j]){
                    if(cols[j]>1){
                        for(int k=1;k<=m;k++){
                            if(cols[k]==0){
                                int temp = arr[i][j];
                                arr[i][j] = arr[i][k];
                                arr[i][k] = temp;
                                cols[j]--;
                                cols[k]++;
                                break;
                            }
                        }
                    }
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }








    }



    return 0;
}