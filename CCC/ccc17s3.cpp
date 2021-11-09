//https://dmoj.ca/problem/ccc17s3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<int>arr(n+1);
    vector<int>freq(4001);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        freq[arr[i]]++;
    }
    vector<set<int>>ans(1e6+1);
    int mx = 0;

    for(int height=2;height<=4000;height++){
        vector<bool>use(2001);
        int cnt = 0;
        for(int i=1;i<=2000;i++){
            
            int comp = height-i;
            if(comp<=0 || comp>2000)continue;

            if(use[i] || use[comp])continue;
            use[i] = true;
            use[comp] = true;
            int add = min(freq[comp], freq[i]);
            if(comp == i)add = freq[i]/2;
            cnt += add;

        }

        mx = max(cnt, mx);
        ans[cnt].insert(height);
    }
    cout<<mx<<" "<<ans[mx].size()<<"\n";




    return 0;
}