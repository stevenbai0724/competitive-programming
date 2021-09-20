//https://codeforces.com/problemset/problem/1335/D
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        vector<string>arr;

        for(int i=1;i<=9;i++){
            string s; cin>>s;

            for(int j=0;j<9;j++){
                if(s[j]=='2')s[j]='1';

            }
            arr.push_back(s);

        }
        for(int i=0;i<9;i++){
            cout<<arr[i]<<"\n";
        }



    }


    return 0;
}