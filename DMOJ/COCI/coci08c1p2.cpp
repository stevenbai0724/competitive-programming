//https://dmoj.ca/problem/coci08c1p2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    string ans; cin>>ans;

    string A = "";
    string B = "";
    string C = "";

    for(int i=1;i<=100;i++){
        A += "ABC";
        B += "BABC";
        C += "CCAABB";
    }

    vector<int>arr{0,0,0};
    int mx = 0;
    for(int i=0;i<n;i++){
        if(ans[i] == A[i])arr[0]++;
        if(ans[i] == B[i])arr[1]++;
        if(ans[i] == C[i])arr[2]++;

        mx = max(arr[0], max(arr[1], arr[2]));
    }

    cout<<mx<<"\n";
    if(arr[0] == mx)cout<<"Adrian\n";
    if(arr[1] == mx)cout<<"Bruno\n";
    if(arr[2] == mx)cout<<"Goran\n";

    



    return 0;
}