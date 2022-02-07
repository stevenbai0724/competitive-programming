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

    int n; cin>>n;
    string s; cin>>s;
    s = " " + s;

    if(n <= 2000){
        double ans = 1.0;   
        int L = 1;
        int R = 1;

        for(int i=1;i<n;i++){
            set<char>st{s[i]};
            for(int j=i+1;j<=n;j++){
                st.insert(s[j]);
                double sz = st.size();
                if( sz/(double)(j-i+1) < ans){
                    
                    ans = sz/(double)(j-i+1);
                    L = i;
                    R = j;
                }
            }
        }
        cout<<L<<" "<<R<<"\n";
    }
    else{
        set<char>unique;
        for(int i=1;i<=n;i++){
            unique.insert(s[i]);
        }
        if(unique.size() == 1){
            cout<<1<<" "<<n<<"\n";
        }
        else{
            double ans = 2.0 /(double)n;
            int L = 1;
            int R = n;
            for(int i=1;i<=n;i++){
                char c = s[i];
                int j = i;
                while(j<n && s[j+1] == c){
                    j++;
                }
                if( (double)1/(double)(j-i+1) < ans){
                    ans = (double)1/(double)(j-i+1);
                    L = i;
                    R = j;
                }
                i = j;
            }
            cout<<L<<" "<<R<<"\n";
        }

    }

    return 0;
}