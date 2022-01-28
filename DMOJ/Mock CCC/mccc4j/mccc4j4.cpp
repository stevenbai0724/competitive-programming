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

    int n, s;
    cin>>n>>s;
    vector<int>ind(n+1);
    vector<vector<pair<int, int>>>arr(n/s+1, vector<pair<int ,int>>(s+1));

    for(int i=1;i<=n/s;i++){
        arr[i][0].first = 1e18;
        for(int j=1;j<=s;j++){
            int x; cin>>x;

            ind[x] = j;
            arr[i][j].second = x;
        }
    }
    for(int i=1;i<=n/s;i++){
        for(int j=1;j<=s*(s-1)/2;j++){
            int a, b;
            char c;
            cin>>a>>b>>c;
            int ind1 = ind[a];
            int ind2 = ind[b];

            if(c == 'W'){
                arr[i][ind1].first+=3;
            }
            else if(c=='L'){
                arr[i][ind2].first+=3;
            }
            else{
                arr[i][ind1].first++;
                arr[i][ind2].first++;
            }

        }
    }
    for(int i=1;i<=n/s;i++){
        sort(arr[i].begin(), arr[i].end(), [](pair<int, int> a, pair<int, int> b){
            if(a.first == b.first)return a.second < b.second;
            return a.first > b.first;
        });
    }

    int k; cin>>k;

    for(int i=1;i<=n/s;i++){
        cout<<arr[i][k].second;
        if(i<n/s)cout<<" ";
    }
    cout<<"\n";

    return 0;
}
