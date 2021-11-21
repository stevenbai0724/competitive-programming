//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){

    int n; cin>>n;
    vector<int>arr(n+1);

    cout<<"? 1 2\n";
    int aMinusB; cin>>aMinusB;
    cout<<flush<<"? 1 2\n";
    int Btimes2; cin>>Btimes2;

    arr[2] = Btimes2/2;
    arr[1] = arr[2] + aMinusB;
    int sum = 0;
    for(int i=3;i<=n;i++){
        cout<<flush<<"? "<<2<<" "<<i<<"\n";
        int diff; cin>>diff;
        arr[i] = (Btimes2 + sum) - diff;
        sum += arr[i];

    }
    cout<<flush<<"! ";
    for(int i=1;i<=n;i++){
        cout<<arr[i];
        if(i<n)cout<<" ";   
    }
    cout<<"\n";


    return 0;
}