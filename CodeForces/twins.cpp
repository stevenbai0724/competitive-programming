//https://codeforces.com/problemset/problem/160/A
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

bool comp(int a, int b){
    return a>b;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n);

    int total = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        total += arr[i];
    }

    sort(arr.begin(), arr.end(), comp);

    int sum = 0;
    int ans = 1;

    for(int x: arr){
        sum +=x;
        if(sum> (total-sum)){
            cout<<ans<<"\n";
            return 0;
        }
        ans ++;
    }

    


    return 0;
}