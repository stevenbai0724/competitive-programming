//https://codeforces.com/contest/1551/problem/B1
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        string s; cin>>s;
        if(s.length()==1){
            cout<<"0\n";
            continue;
        }
        vector<int>freq(26);

        for(char ch: s){
            freq[ch-97]++;
        }

        bool red = true;

        int cntRed = 0;
        int cntGreen = 0;


        for(int i=0; i< 26;i ++){
            if(freq[i]>1){
                cntRed++;
                cntGreen++;
            }
            if(freq[i]==1){
                if(red){
                    cntRed++;
                    red = false;
                }
                else{
                    cntGreen++;
                    red = true;
                }
            }
        }
        cout<<min(cntRed, cntGreen)<<"\n";
    

    }


    return 0;
}