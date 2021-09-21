//https://dmoj.ca/problem/mwc15c1p5
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    map<char, int>mp;

    for(int i='a';i<='z';i++){
        mp[(char)i] = i-96;
    }

    for(int i='A';i<='Z';i++){
        mp[(char)i] = i-64;

    }
    vector<vector<int>>arr(10);
    arr[2] = {6,2,4,8};
    arr[3] = {1,3,9,7};
    arr[4] = {6,4};
    arr[7] = {1,7,9,3};
    arr[8] = {6,8,4,2};
    arr[9] = {1,9};

    string s, t;
    cin>>s>>t;

    int sum1 = 0, sum2 = 0;
    for(int i=0;i<s.length();i++){
        int ind = i+1;
        int num = mp[s[i]]%10;
        
        if(num%10 == 1 || num%10 == 5 || num%10 == 6 || num%10 == 0)sum1 += num%10;
        else if(num == 2 || num == 3 || num == 7 || num == 8) sum1 += arr[num][ind%4];
        else sum1 += arr[num][ind%2];

    }
    for(int i=0;i<t.length();i++){
        int ind = i+1;
        int num = mp[t[i]]%10;
        
        if(num%10 == 1 || num%10 == 5 || num%10 == 6 || num%10 == 0)sum2 += num%10;
        else if(num == 2 || num == 3 || num == 7 || num == 8) sum2 += arr[num][ind%4];
        else sum2 += arr[num][ind%2];

    }
    sum1 %= 10, sum2 %=10;
    if(sum1== 0) sum1 = 10;
    if(sum2== 0) sum2 = 10;
    cout<<sum1+sum2<<"\n";

    return 0;
}