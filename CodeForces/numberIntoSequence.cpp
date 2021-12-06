//https://codeforces.com/contest/1454/problem/D
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
        int mxCnt = 0;
        int num = 0;
        map<int, int>mp;

        int temp = n;
        for(int i=2;i*i<=n;i++){
            while(temp%i == 0){
                temp /= i;
                mp[i] ++;
                if(mp[i] > mxCnt){
                    mxCnt = mp[i];
                    num = i;
                }
            }
        }
        if(temp > 1){
            mp[temp]++;
            if(mp[temp] > mxCnt){
                mxCnt = mp[temp];
                num = temp;
            }
        }
        if(mxCnt == 1){
            cout<<1<<"\n"<<n<<"\n";
        }
        else{
            cout<<mxCnt<<"\n";
            for(int i=1;i<mxCnt;i++){
                n /= num;
                cout<<num<<" ";
            }
            cout<<n<<"\n";
        }


    }

    return 0;
}