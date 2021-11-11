//https://dmoj.ca/problem/fhc15c1p1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<bool>prime(1e7+1, true);
    vector<int>SPF(1e7+1);
    for(int i=2;i*i<=1e7;i++){
        if(prime[i]){
            SPF[i] = i;
            for(int j=2;j*i<=1e7;j++){
                if(prime[i*j]){
                    SPF[i*j] = i;
                }
                prime[i*j] = false;
            }
        }
    }
    vector<vector<int>>psa(9, vector<int>(1e7+1));


    for(int i=2;i<=1e7;i++){
        if(SPF[i]==0){
            SPF[i] = i;
        }
        set<int>s;
        int temp = i;
        while(temp!=1){
            s.insert(SPF[temp]);
            temp/=SPF[temp];
        }
        for(int j=1;j<=8;j++){
            psa[j][i] = psa[j][i-1];
        }
        psa[s.size()][i]++;
        
    }

    int t; cin>>t;
    for(int i = 1; i <= t; i++){
        int a, b, k;
        cin>>a>>b>>k;
        if(k>=9){
            cout<<"Case #"<<i<<": "<<0<<"\n";
        }
        else{
            cout<<"Case #"<<i<<": "<<psa[k][b]-psa[k][a-1]<<"\n";
        }
    }
    




    return 0;
}