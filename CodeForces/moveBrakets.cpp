//https://codeforces.com/problemset/problem/1374/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>arr;//(
        vector<int>arr2;//)
        int count = 0;
        string s; cin>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='(')arr.push_back(i);
            else arr2.push_back(i);
        }
        int index = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[index]>arr2[i]){
                count++;
                continue;
            }
            else{
                index++;
            }
        }
        cout<<count<<"\n";
    }
   


    return 0;
}