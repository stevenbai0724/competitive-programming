//https://codeforces.com/problemset/problem/1398/B
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        vector<int>arr;
        int ans = 0;
        int count = 0;
        for(int i=0;i<s.length();i++){

            if(s[i]=='0'){
                if(count!=0)arr.push_back(count);
                count = 0;
            }
            if(s[i]=='1'){
                count++;
            }
            if(i==s.length()-1){
                if(count!=0)arr.push_back(count);
            }
        }
        sort(arr.begin(), arr.end(), greater<int>());

        for(int i=0;i<arr.size();i+=2){
            ans+=arr[i];
        }
        cout<<ans<<"\n";

    }

    return 0;
}