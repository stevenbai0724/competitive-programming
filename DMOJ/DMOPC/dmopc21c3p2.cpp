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
    cin.tie(nullptr)->sync_with_stdio(false);


    int k ;cin>>k;

    if(k>500000500000){
        cout<<-1<<"\n";
        return 0;
    }
    if(k == 0){
        cout<<"1\n1\n";
        return 0;
    }
    vector<int>arr{0};

    for(int i=2;i<=1e6+1;i++){
        arr.push_back(i*(i-1)/2);
    }
    if(*lower_bound(arr.begin(), arr.end(), k) == k){
        cout<<lower_bound(arr.begin(), arr.end(), k) - arr.begin()<<"\n";
        for(int i=1;i<=lower_bound(arr.begin(), arr.end(), k) - arr.begin() ;i++){
            cout<<"0";
            if(i<lower_bound(arr.begin(), arr.end(), k) - arr.begin())cout<<" ";
        }
        cout<<"\n";
        return 0;
    }
    
    for(int x: arr){
        if(x > k){
            cout<<"-1\n";
            return 0;
        }

        if(*lower_bound(arr.begin(), arr.end(), k-x) == k-x){
            int E = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            int O = lower_bound(arr.begin(), arr.end(), k-x) - arr.begin() + 1;
            E = max(E,(int)0);
            O = max(O,(int)0);
            if(E+O > 1e6){
                cout<<"-1\n";
                return 0;
            }
            vector<int>arr(O+E+2);
            cout<<O+E<<"\n";
            arr[1 + E] = 1;
            for(int i=1;i<=O+E;i++){
                cout<<arr[i];
                if(i<O+E)cout<<" ";
            }
            cout<<"\n";
            return 0;
            
        }

    }
    cout<<-1<<"\n";

    return 0;
}