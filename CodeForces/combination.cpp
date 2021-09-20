//https://codeforces.com/problemset/problem/155/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    int temp = t;
    int c = 1e9;
    vector<int>arr;
    int count = 1;
    int points = 0;

    while(t--){
        int a,b;
        cin>>a>>b;
        
        arr.push_back(b*c + a);
    }
    sort(arr.begin(), arr.end());

    while(count!=0 && !arr.empty()){
        int cura = arr.back()%c;
        int curb = arr.back()/c;
        arr.pop_back();

        count--;
        points += cura;
        count += curb;

    }   
    cout<<points;


    return 0;
}