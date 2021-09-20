//https://codeforces.com/problemset/problem/1454/C
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

   
    int t; cin>>t;

    for(t; t>0;t--){
        
        int n; cin>>n;
        int ans = 1e9;
        vector<int>arr; //no consecutive elements that are equal
        vector<int>arr2(n+1); //input
        vector<int>res(n+1, 1);  //i will appear res[i] times

        for(int i =1;i<=n;i++){
            cin>>arr2[i];
        }
        for(int i =1;i<n;i++){
            if(arr2[i]!=arr2[i+1]) arr.push_back(arr2[i]);
        }
        arr.push_back(arr2[n]);

        
        for(int i=0;i<arr.size();i++){
            res[arr.at(i)]++;
        }
        res[arr.at(0)]--;
        res[arr.at(arr.size()-1)]--;
        
        for(int i = 0;i<arr.size();i++){
            ans = min(ans, res[arr.at(i)]);
        }
        cout<<ans<<"\n";

   }
    return 0;
}