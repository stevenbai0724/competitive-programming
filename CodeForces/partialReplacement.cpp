//https://codeforces.com/problemset/problem/1506/B
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int t; cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;
        string s; cin>>s;
        vector<char>arr(n+1);
        int start, end;
        bool first = true;
        for(int i=1;i<=n;i++){
            arr[i] = s[i-1];

            if(arr[i]=='*'){
                if(first){
                    start = i;
                    first = false;
                }
                end = i;
            }
        }
        if(start==end){
            cout<<1<<"\n";
            continue;
        }
        int cur = start + k;
        int ans = 2;
        while(true){
            if(cur>=end)break;

            while(true){
                if(arr[cur]=='*'){
                    ans++;
                    cur+=k;
                    break;
                }
                cur--;
            }
        }
        cout<<ans<<"\n";

    }
    return 0;
}