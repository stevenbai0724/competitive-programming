//https://dmoj.ca/problem/coci12c3p3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;
    vector<vector<int>>psa(21, vector<int>(n+1));
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        string s ; cin>>s;
        int len = s.length();
        arr[i] = len;
        for(int j=1;j<=20;j++){
            psa[j][i] = psa[j][i-1];
        }
        psa[len][i]++;
    }
    long long cnt = 0;
    for(int i =1;i<n;i++){
        int R = min(n, i+k);
        int len = arr[i];
        cnt += psa[len][R] - psa[len][i];
    }
    cout<<cnt<<"\n";

    return 0;
}