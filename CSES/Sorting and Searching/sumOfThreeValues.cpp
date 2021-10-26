//https://cses.fi/problemset/task/1641
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, x;
    cin>>n>>x;

    vector<pair<int, int>>arr(n+1);

    arr[0] = {-1e9, -1e9};

    for(int i=1;i<=n;i++){
        int num; cin>>num;
        arr[i] = {num, i};
    }
    sort(arr.begin(), arr.end());

    for(int i=1;i<=n;i++){
        int cur = arr[i].first;
        int ind = arr[i].second;
        int L = 1;
        int R = n;
        while(L<R){
            if(cur+arr[L].first + arr[R].first < x){
                L++;
            }
            else if(cur+arr[L].first + arr[R].first > x){
                R--;
            }
            else {
                if(ind != arr[L].second && ind != arr[R].second){
                    cout<<ind<<" "<<arr[L].second<<" "<<arr[R].second<<"\n";
                    return 0;
                }
                else{
                    if(ind == arr[L].second)L++;
                    else R--;
                }
            }
        }
    }

    cout<<"IMPOSSIBLE\n";


    return 0;
}