//https://codeforces.com/problemset/problem/1473/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    while(n--){
        string s, t;
        cin>>s>>t;
        int n = s.length(), m = t.length();
        int lcm = n*m / __gcd(n,m);
        string s1 = "", s2="";
        
        while(s1.length()!=lcm){
            s1+=s;
        }
        while(s2.length()!=lcm){
            s2+=t;
        }
        if(s1==s2)cout<<s1<<"\n";
        else cout<<-1<<"\n";

    }
    
    return 0;
}