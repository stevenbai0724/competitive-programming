#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, l;
vector<int>arr;
bool good(int num){
    double radius = num/10.0;


    if(radius<(arr[0]-0))return false;
    if(radius<(l-arr[n-1]))return false;

    for(int i=0;i<n-1;i++){
    
        if(arr[i] + (radius*2) < arr[i+1])return false;
    }
    return true;

}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);



    cin>>n>>l;

    arr.resize(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    int lo = -1;
    int hi = 1e17;

    
    while(lo+1<hi){
        int m = (lo+hi)/2;

        if(good(m))hi = m;
        else lo = m;
    }

    cout<<setprecision(20)<<fixed<<hi/10.0<<"\n";

    


    return 0;
}