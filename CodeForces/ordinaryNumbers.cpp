//https://codeforces.com/contest/1520/problem/B
//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        if(n<10){
            cout<<n<<"\n";
            continue;
        }
        string temp = to_string(n);
        int len = temp.length();
        int ans = 9;
        
        string eleven = "";
        for(int i=0;i<len;i++){
            eleven+='1';
        }
        int bound = (temp[0]-48) * (stoi(eleven));

        if(stoi(temp)<bound){
            ans += (len-2)*9 + temp[0]-49;
        }
        else ans += (len-2)*9 + temp[0]-48;

        cout<<ans<<"\n";

        
    }
    return 0;
}