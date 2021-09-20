#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);


    int n; cin>>n;
    cout<<n<<" ";
    while(n!=1){
        if(n%2 ==0)n/=2;
        else n = (n*3)+1;

        cout<<n<<" ";

    }
    return 0;
}