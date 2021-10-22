//https://dmoj.ca/problem/ccc06j1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<vector<int>>arr(5);

    arr[1] = {0,461,431,420,0};
    arr[2] = {0,100,57,70,0};
    arr[3] = {0,130,160,118,0};
    arr[4] = {0,167,266,75,0};

    int sum = 0;
    for(int i=1;i<=4;i++){
        int j; cin>>j;
        sum += arr[i][j];
    }
    cout<<"Your total Calorie count is "<<sum<<"."<<"\n";

    return 0;
}