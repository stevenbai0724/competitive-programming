//https://dmoj.ca/problem/dmopc17c5p2
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

    string s; cin>>s;
    vector<int>zeroInd, oneInd;

    for(int i=0;i<(int)s.length();i++){
        if(s[i] == '0'){
            zeroInd.push_back(i+1);
        }
        else oneInd.push_back(i+1);
    }

    int q; cin>>q;
    while(q--){
        int x, y, z;
        cin>>x>>y>>z;
        if(z == 0){
            auto it = lower_bound(zeroInd.begin(), zeroInd.end(), x);
            int ind = it - zeroInd.begin();
            int move = y-1;

            if(ind + move >= zeroInd.size()){
                cout<<-1<<"\n";
            }
            else{
                cout<<zeroInd[ind+move]<<"\n";
            }

        }
        else{
            auto it = lower_bound(oneInd.begin(), oneInd.end(), x);
            int ind = it - oneInd.begin();
            int move = y-1;

            if(ind + move >= oneInd.size()){
                cout<<-1<<"\n";
            }
            else{
                cout<<oneInd[ind+move]<<"\n";
            }
        }
    }

    return 0;
}