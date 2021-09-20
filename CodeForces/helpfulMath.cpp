//https://codeforces.com/problemset/problem/339/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin>>s;
    vector<int>arr;
    for(int i=0;i<s.length();i+=2){
        arr.push_back(((int)s[i])-48);
    }
    sort(arr.begin(), arr.end());
    for(int i=0;i<arr.size();i++){
        if(i==arr.size()-1){
            cout<<arr.at(i);
            return 0;
        }
        cout<<arr.at(i)<<"+";
    }
    return 0;
}