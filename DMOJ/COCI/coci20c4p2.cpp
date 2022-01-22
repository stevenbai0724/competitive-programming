//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//order_of_key
int mod = 1e9 + 7;
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    vector<bool>prime(1e7+1, true);
    prime[1] = false;
    for(int i =2;i*i<=1e7;i++){
        if(prime[i]){
            for(int j=2;j*i<=1e7;j++){
                prime[i*j] = false;
            }
        }
    }
    vector<int>primeNums;

    for(int i=2;i<=1e7;i++){
        if(prime[i])primeNums.push_back(i);
    }

    while(t--){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        a--;
        c--;
        bool good = true;

        for(int i : primeNums){

                int num = 0;
                int den = 0;

                int div = i;
                while(d >= div){
                    num += (d/div);
                    div*=i;
                }
                div = i;
                while(a >= div){
                    num += (a/div);
                    div*=i;
                }
                div = i;
                while(c >= div){
                    den += (c/div);
                    div*=i;
                }
                div = i;
                while(b >= div){
                    den += (b/div);
                    div*=i;
                }

                if(num < den)good = false;
            
        }
        if(good)cout<<"DA\n";
        else cout<<"NE\n";
    }
    

    return 0;
}
