//
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
    

    int n; cin>>n;

    vector<int>arr(n+1);
    vector<int>sorted(n+1);
    sorted[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sorted[i] = arr[i];
    }
    sort(sorted.begin(), sorted.end());
    int l = 0, r = 0;

    for(int i=1;i<=n;i++){
        if(arr[i]!=sorted[i]){
            l = i;
            break;
        }
    }
    for(int i=n;i>=1;i--){
        if(arr[i]!=sorted[i]){
            r = i;
            break;
        }
    }
    if(r == 0 && l==0){
        cout<<"yes\n";
        cout<<"1 1\n";
        return 0;
    }
    reverse(arr.begin()+l, arr.begin()+1+r);

    if(arr==sorted){
        cout<<"yes\n";
        cout<<l<<" "<<r<<"\n";
    }
    else{
        cout<<"no\n";
    }


    return 0;
}