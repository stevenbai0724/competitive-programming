//https://dmoj.ca/problem/ccc13j2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin>>s;

    set<char>arr{'I','O','S','H','Z','X','N'};

    bool good = true;

    for(auto c: s) if(arr.find(c)==arr.end())good = false;

    cout<<(good ? "YES\n" : "NO\n");



    return 0;
}