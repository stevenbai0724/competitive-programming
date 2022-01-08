//https://dmoj.ca/problem/bsspc21s1
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

    int n, m;
    cin>>n>>m;

    vector<vector<char>>arr(n+1, vector<char>(m+1));

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            set<char>st;
            if(arr[i][j]!='.')st.insert(arr[i][j]);
            if(arr[n-i+1][j]!='.')st.insert(arr[n-i+1][j]);
            if(arr[i][m-j+1]!='.')st.insert(arr[i][m-j+1]);
            if(arr[n-i+1][m-j+1]!='.')st.insert(arr[n-i+1][m-j+1]);

            if(st.size() == 0){
                arr[i][j] = arr[n-i+1][j] = arr[i][m-j+1] = arr[n-i+1][m-j+1] = 'z';
            }
            else if(st.size() == 1){
                char c = *st.begin();

                arr[i][j] = arr[n-i+1][j] = arr[i][m-j+1] = arr[n-i+1][m-j+1] = c;
            }
            else {
                
                cout<<-1<<"\n";
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }



    return 0;
}
