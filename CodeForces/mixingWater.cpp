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
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int ti; cin>>ti;
    while(ti--){
        double h, c, t;
        cin>>h>>c>>t;
        double avg = (h+c)/2.0;

        if(t == h){
            cout<<1<<"\n";
        }
        else if(t <= avg){
            cout<<2<<"\n";
        }
        else{
            int ans = 1;
            double mn = h - t;
            if(t - avg < mn){
                mn = t - avg;
                ans = 2;
            }

            int x = (h-t)/(t+t-h-c);
            x -= 6;
            x = max(x, (int)1);

            for(int i=x;i<=x+501;i++){
                double cur = (h*(i) + c*(i-1))/(double)(i+i-1);
                if(abs(cur - t) < mn){
                    mn = abs(cur-t);
                    ans = i+i-1;
                }

            }
            cout<<ans<<"\n";
        }


    }

    return 0;
}
