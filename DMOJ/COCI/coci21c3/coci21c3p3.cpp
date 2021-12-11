//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
bool comp(pair<int, int>a, pair<int, int>b){
    return a.second<b.second;
}
bool comp2(pair<int, int>a, pair<int, int>b){
    if(a.first == b.first)return a.second<b.second;
    else return a.first > b.first;
}
bool comp3(pair<int, int>a, pair<int, int>b){
    if(a.second == b.second)return a.first < b.first;
    else return a.second < b.second;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;

    vector<pair<int, int>>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }

    if(k==1){
        sort(arr.begin(), arr.end(), comp3);
        int ind = 1;
        int cnt = 0;
        int sum = 0;
        for(auto p: arr){
            if(p.second >= ind){
                ind++;
                cnt++;
                sum += p.first;
            }
        }
        cout<<cnt<<" "<<sum<<"\n";
        return 0;
    }


    vector<pair<int, int>>ans;
    for(int i=0;i<(1<<n);i++){
        vector<pair<int, int>>temp;
        for(int j=0;j<n;j++){
            if((1<<j)&i){
                temp.push_back(arr[j]);
            }
        }
        sort(temp.begin(), temp.end(), comp);
        int ind = 1;
        bool found = true;
        int sum = 0;
        for(auto p: temp){
            if(p.second<ind)found = false;
            ind++;
            sum += p.first;
        }
        if(found){
            ans.push_back({temp.size(), sum});
        }

    }
    sort(ans.begin(), ans.end(), comp2);
    for(int i=0;i<k;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }

    return 0;
}