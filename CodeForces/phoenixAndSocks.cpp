//https://codeforces.com/problemset/problem/1515/D
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    
    while(t--){
        int n, l, r;
        cin>>n>>l>>r;

        vector<int>freq(n+1), freqL(n+1), freqR(n+1);

        for(int i=1;i<=n;i++){
            int x; cin>>x;
            freq[x]++;
            if(i<=l)freqL[x]++;
            else freqR[x] ++ ;
        }
        if(l<r){
            swap(freqL, freqR);
            swap(l, r);
        }

        for(int i=1;i<=n;i++){
            int mn = min(freqL[i], freqR[i]);
            l-=mn;
            r-=mn;
            freqL[i]-=mn;
            freqR[i]-=mn;
        }
        int ans = 0;

        for(int i=1;i<=n;i++){
            int left = l-r;
            int have = freqL[i]/2;
            int fill = min(left, have*2);
            ans += fill/2;

            l-=fill;
        }
        ans += (l-r)/2 + (l+r)/2;
        cout<<ans<<"\n";




    }


    return 0;
}