//https://codeforces.com/problemset/problem/1419/D2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    int L = 0;
    int R = (n-1)/2 +1 ;
    while(L+1<R){
        if(n<=2) break;
        int m = (L+R)/2;
        bool good = true;
        int ind = 1;
        for(int i=n-m;i<n;i++){
            if(arr[i]<=arr[ind]) good = false;
            ind ++ ;
        }
        
        if(good)L = m;
        else R = m;

    }
    cout<<L<<"\n";

    bool big = true;
    deque<int>small, large;
    for(int i=1;i<=L;i++){
        small.push_back(arr[i]);
    }
    for(int i=n-L;i<=n;i++){
        large.push_back(arr[i]);
    }
    while(!small.empty() || !large.empty()){
        if(big){
            big = false;
            cout<<large.front()<<" ";
            large.pop_front();
        }
        else {
            big = true;
            cout<<small.front()<<" ";
            small.pop_front();
        }
    }
    for(int i=L+1;i<n-L;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    
   



    return 0;
}