//https://codeforces.com/contest/1551/problem/B2
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n, k;
        cin>>n>>k;

        vector<int>arr(n+1);
        vector<int>freq(n+1);
        vector<vector<int>>ind(n+1);
        vector<int>ans(n+1);
        vector<int>colCount(k+1);
        vector<int>lastCol(k+1); //lastCol[i] is the index of the last occurence of colour i


        for(int i=1;i<=n;i++){
            cin>>arr[i];
            freq[arr[i]] ++;
            ind[arr[i]].push_back(i);
        }
        int col = 1;

        for(int i=1;i<=n;i++){
            if(freq[i]==0)continue;
            if(freq[i] < k){
                for(int j=0;j<ind[i].size();j++){
                    int curInd = ind[i][j];
                    ans[curInd] = col;
                    colCount[col]++;
                    lastCol[col] = curInd;

                    col++;
                    if(col>k) col = 1;
                }
            }
            else{
                for(int j=0;j<k;j++){
                    int curInd = ind[i][j];
                    ans[curInd] = col;
                    colCount[col]++;
                    lastCol[col] = curInd;

                    col++;  
                    if(col>k) col = 1;
                }
            }
        }

        int mn = 1e18;

        for(int i=1;i<=k;i++){
            mn = min(mn, colCount[i]);
        }

        for(int i=1;i<=k;i++){
            if(colCount[i]!=mn){
                ans[lastCol[i]] = 0;
            }
        }
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";

    }


    return 0;
}