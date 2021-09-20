//https://codeforces.com/problemset/problem/1110/A
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;
    int oddCount = 0;

    for(int i=1;i<=k;i++){
        int x; cin>>x;
        if(i==k){
            oddCount+=(x%2);
            continue;
        }
        if(n%2==0 || x%2==0)continue;
        oddCount++;
    }
    if(oddCount%2==0)cout<<"even\n";
    else cout<<"odd\n";
    
   

    return 0;
}