//https://dmoj.ca/problem/si17c1p8
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

int n, t;
vector<int>arr;


int solve(int use, int sum, int count){
    if(use==n){
        if(sum==t){
            count++;
        }
        return count;
    }

    count = solve(use + 1, sum + arr[use+1], count);
    count = solve(use + 1, sum, count);

    return count;
}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>t;
    arr.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    cout<<solve(0, 0, 0)<<"\n";

    return 0;
}