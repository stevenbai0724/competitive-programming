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
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int>temp = arr;
        sort(temp.begin(), temp.end());
        if(arr == temp)cout<<"0\n";
        else if(arr[0]==n && arr[n-1] ==1)cout<<"3\n";
        else if(arr[0] == 1 || arr[n-1] == n)cout<<"1\n";
        else cout<<"2\n";
    }
    

    return 0;
}