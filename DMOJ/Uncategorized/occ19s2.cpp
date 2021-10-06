//https://dmoj.ca/problem/occ19s2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>arr;

    for(int len = 1; len <= 18; len++){
        for(int i=0;i<(1<<len);i++){
            string s = "";
            for(int k=1;k<=len;k++){
                s += "2";
            }

            for(int j=0;j<len;j++){
                if((1<<j)&i){
                    s[j] = '3';
                }

            }

            arr.push_back(stol(s));


        }
    }
    sort(arr.begin(), arr.end());

    int n; cin>>n;

    cout<<upper_bound(arr.begin(), arr.end(), n)-arr.begin()<<"\n";





    return 0;
}