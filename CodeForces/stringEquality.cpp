//
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    
    while(t--){
        int n, k;
        cin>>n>>k;
        string a, b;
        cin>>a>>b;

        vector<int>freq1(26);
        vector<int>freq2(26);

        for(int i=0;i<n;i++){
            freq1[a[i]-97]++;
            freq2[b[i]-97]++;
        }
        bool ans = true;
        for(int i=0;i<26;i++){

            if(freq1[i]<freq2[i] || (freq1[i]-freq2[i])%k){
                ans = false;
                break;
            }
            freq1[i]-=freq2[i];
            freq1[i+1] += freq1[i];
        }
        if(ans)cout<<"Yes\n";
        else cout<<"No\n";


    }


    return 0;
}