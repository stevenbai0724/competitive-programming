//https://dmoj.ca/problem/cco07p2
#include <bits/stdc++.h>
using namespace std;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    set<string>s;

    while(t--){
        vector<int>arr(6);
        string ans = "";
        for(int i=0;i<6;i++){
            cin>>arr[i];
        } 
        
        //lexicographically smallest ordering 
        for(int i=0;i<6;i++){
            string temp = "";
            for(int j=0;j<6;j++){
                temp += to_string(arr[(i+j)%6]) + " ";
            }
            if(temp<ans || ans=="")ans = temp;
        }
        reverse(arr.begin(), arr.end());
        for(int i=0;i<6;i++){
            string temp = "";
            for(int j=0;j<6;j++){
                temp += to_string(arr[(i+j)%6]) + " ";
            }
            if(temp<ans)ans = temp;
        }
        auto it = s.find(ans);

        if(it!=s.end()){
            cout<<"Twin snowflakes found.\n";
            return 0;
        }
        s.insert(ans);
    }
    cout<<"No two snowflakes are alike.\n";
}