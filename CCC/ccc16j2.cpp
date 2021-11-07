//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<vector<int>>arr(5, vector<int>(5));

    set<int>s;

    for(int i=1;i<=4;i++){
        int sum = 0;
        for(int j=1;j<=4;j++){
            cin>>arr[i][j];
            sum += arr[i][j];
        }
        s.insert(sum);
    }

    for(int j=1;j<=4;j++){
        int sum = 0;
        for(int i=1;i<=4;i++){
            sum += arr[i][j];
        }
        s.insert(sum);
    }
    cout<<(s.size()==1 ? "magic" : "not magic")<<"\n";



    return 0;
}