//https://dmoj.ca/problem/ccc02s1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>arr(5);
    for(int i=1;i<=4;i++){
        cin>>arr[i];
    }
    int target; cin>>target;
    int mn = 1e18;
    int cnt = 0;
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            for(int k=0;k<=100;k++){
                for(int l=0;l<=100;l++){
                    if(i * arr[1] + j * arr[2] + k * arr[3] + l*arr[4] == target){
                        cnt ++;
                        mn = min(mn, i+j+k+l);
                        cout<<"# of PINK is "<<i<<" # of GREEN is "<<j<<" # of RED is "<<k<<" # of ORANGE is "<<l<<"\n";
                    }
                }
            }
        }
    }
    cout<<"Total combinations is "<<cnt<<".\n";
    cout<<"Minimum number of tickets to print is "<<mn<<".\n";

    return 0;
}