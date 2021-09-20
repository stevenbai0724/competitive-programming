//https://codeforces.com/problemset/problem/141/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s1, s2, ans;
    cin>>s1>>s2>>ans;
    vector<int>arr1(91, 0);
    vector<int>arr2(91, 0);

    for(int i=0;i<s1.length();i++){
        arr1[(int)s1[i]]++;
    }
    for(int i=0;i<s2.length();i++){
        arr1[(int)s2[i]]++;
    }
    for(int i=0;i<ans.length();i++){
        arr2[(int)ans[i]]++;
    }
    for(int i =65;i<=90;i++){
        if(arr1[i]!=arr2[i]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

    return 0;
}