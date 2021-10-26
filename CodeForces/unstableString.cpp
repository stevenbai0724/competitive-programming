//https://codeforces.com/problemset/problem/1535/C
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.length();
        vector<pair<int, int>>arr; //val, ind
        vector<pair<int, int>>seg{{-1,-1}};
        for(int i=0;i<n;i++){
            if(s[i]=='1' || s[i]=='0'){
                arr.push_back({s[i]-48,i});
            }
        }
        if(arr.size()==0){
            cout<<n*(n+1)/2<<"\n";
            continue;
        }

        for(int i=0;i<arr.size();i++){
            int j = i;
            int curVal = arr[i].first;
            int curInd = arr[i].second;
            int startInd = curInd;

            while(j<arr.size()-1 && (abs(curVal-arr[j+1].first) == (arr[j+1].second-curInd)%2 )){
                j++;
                curVal = arr[j].first;
                curInd = arr[j].second;

            }
            seg.push_back({startInd, curInd});
            i = j;

        }
        seg[1].first = 0;
        seg.push_back({n, n});
        seg[seg.size()-2].second = n-1; 

        int ans = 0;

        int INDEX = 1;
        for(auto p: seg){
            if(p.first==-1 || p.first == n)continue;
            int len = p.second-p.first+1;


            int L = p.first - seg[INDEX-1].second -1;
            int R = seg[INDEX+1].first - p.second -1;

            len += L+R;
            
            ans += len*(len+1)/2;

            ans -= (R)*(R+1)/2;

            INDEX++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}