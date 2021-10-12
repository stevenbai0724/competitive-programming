//https://dmoj.ca/problem/dmopc15c6p5
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;
    vector<int>arr(n+2);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int ans = n;
    set<int>s;
    vector<int>freq(3e6+2);
    int j=0;
    int mn,mx;
    for(int i=1;i<=n;i++){
        if(j<i){
            freq[arr[i]]++;
            if(freq[arr[i]]==1){
                s.insert(arr[i]);
            }
            j = i;
        }
        ans += max((int)0,j-i);
        if(i>1){
            freq[arr[i-1]]--;
            if(freq[arr[i-1]]==0){
                s.erase(arr[i-1]);
            }
            
        }
        mn = *s.begin();
        mx = *s.rbegin();

        while(j<n && (max(mx, arr[j+1])-min(mn, arr[j+1]))<=k){
            j++;
            freq[arr[j]]++;
            if(freq[arr[j]]==1){
                s.insert(arr[j]);
            }
            mn = min(mn, arr[j]);
            mx = max(mx, arr[j]);
            ans++;
        }
        // cout<<ans<<"\n";


    }
    cout<<ans<<"\n";







    return 0;
}