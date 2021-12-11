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

    int n, k;
    cin>>n>>k;

    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    for(int len = 1; len <= n; len++){
        if(len * k > n)break;
        for(int i=1;i<=n-len+1;i++){
            vector<int>temp;
            for(int j=i;j<i+len;j++){
                temp.push_back(arr[j]);
            }
            int m = temp.size();
            if(m * k > n)continue;

            for(int l=1;l<k;l++){
                for(int j=0;j<m;j++){
                    temp.push_back(temp[j]);
                }
            }
            int newLen = m*k;
            for(int j=1;j<=n-newLen+1;j++){
                vector<int>temp2;
                for(int l=j;l<j+newLen;l++){
                    temp2.push_back(arr[l]);
                }
                if(temp2 == temp){
                    cout<<len<<"\n";
                    for(int l=0;l<len;l++){
                        cout<<temp[l]<<" ";
                    }
                    cout<<"\n";
                    return 0;
                }
            }


        }
    }
    cout<<-1<<"\n";

    return 0;
}