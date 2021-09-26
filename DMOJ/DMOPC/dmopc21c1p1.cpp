//https://dmoj.ca/problem/dmopc21c1p1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<int>arr(n+1);

    int duke = 0, alice = 0;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]&1){
            alice += (arr[i]/2)+1;
        }
        else duke += arr[i]/2;
    }

    if(alice>=duke)cout<<"Alice\n";
    else cout<<"Duke\n";

    return 0;
}