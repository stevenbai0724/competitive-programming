//https://dmoj.ca/problem/dmopc19c3p2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>fact(20);

    fact[0] = 1;

    for(int i=1;i<=19;i++){
        fact[i] = fact[i-1]*i;
     
    }

    int n, k;
    cin>>n>>k;

    string s; cin>>s;

    vector<int>freq(26);

    for(char c: s){
        if((int)c>=97){
            freq[(int)c-97]++;
        }
    }

    if(k==0){
        int ans = fact[n];
        for(int i=0;i<26;i++){
            ans/=fact[freq[i]];
        }
        cout<<ans<<"\n";
    }
    if(k==1){
        int ans = 0;
        for(int i=0;i<26;i++){
            vector<int>temp = freq;
            temp[i]++;
            int cnt = fact[n];
            for(int j=0;j<26;j++){
                cnt/=fact[temp[j]];
            }
            ans+=cnt;
        }
        cout<<ans<<"\n";

    }
    if(k==2){
        int ans = 0;
        for(int i=0;i<26;i++){
            vector<int>temp = freq;
            temp[i]++;
            for(int j=i;j<26;j++){
                
                temp[j]++;
                if(j-i>0)temp[j-1]--;

                int cnt = fact[n];
                for(int x=0;x<26;x++){
                    cnt /= fact[temp[x]];
                }
                ans +=cnt;

            }
            
        }
        cout<<ans<<"\n";
    }




    return 0;
}