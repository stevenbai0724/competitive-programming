//https://codeforces.com/problemset/problem/1490/F
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;


        set<int>st;
        vector<int>freqfreq(n+1);
        vector<int>arr(n+1);
        for(int i=1;i<=n;i++){
            int x; cin>>x;
            arr[i] = x;
            st.insert(x);
        }  
        sort(arr.begin(), arr.end());

        for(int i=1;i<=n;i++){
            int j = i;

            while(j<n && arr[j+1] == arr[j]){
                j++;
            }
            freqfreq[j-i+1] ++ ;
            i = j;
        }

        vector<int>mult{0}, freq{0};

        for(int i=1;i<=n;i++){
            if(freqfreq[i]>0){
                freq.push_back(i);
            }
        }

        for(int i=1;i<freq.size();i++){
            mult.push_back(freq[i] * freqfreq[freq[i]]);

        }
        int m = freq.size()-1;

        vector<int>psaMult(m+2), psaFF(m+2);

        for(int i=1;i<=m;i++){
            psaMult[i] = psaMult[i-1] + mult[i];
            psaFF[i] = psaFF[i-1] + freqfreq[freq[i]];
        }
        int ans = 1e18;
        for(int i=1;i<=m;i++){
            int cur = freq[i];
            ans = min(ans, psaMult[i-1] + psaMult[m]-psaMult[i]-(cur*(psaFF[m]-psaFF[i])));
        }   
        
        cout<<ans<<"\n";
        
    }


    return 0;
}