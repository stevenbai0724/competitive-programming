//https://codeforces.com/problemset/problem/1370/C
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

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n == 1){
            cout<<"FastestFinger\n";
        }
        else if(n == 2){
            cout<<"Ashishgup\n";
        }
        else if(n&1){
            cout<<"Ashishgup\n";
        }
        else{
            int twoCnt = 0;
            int oddCnt = 0;
            int temp = n;
            
            for(int i=2;i*i<=n;i++){
                while(temp%i == 0){
                    temp /=i;
                    if(i == 2)twoCnt++;
                    else oddCnt++;
                }
            }
            if(temp > 1)oddCnt++;

            if(twoCnt > 1){
                if(oddCnt > 0)cout<<"Ashishgup\n";
                else cout<<"FastestFinger\n";
                
            }
            else{
                if(oddCnt == 1)cout<<"FastestFinger\n";
                else cout<<"Ashishgup\n";
            }
            
        }
    }

    return 0;
}