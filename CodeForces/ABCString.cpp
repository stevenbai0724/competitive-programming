//https://codeforces.com/problemset/problem/1535/B
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool comp(int a, int b){
    return a>b;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    

    int t; cin>>t;
    while(t--){
        
        string s; cin>>s;
        int n = s.length();
        bool yes = false;
        for(int a = 1; a<=2; a++){
            for(int b=1; b<=2; b++){
                for(int c = 1; c<=2; c++){
                    vector<int>arr;

               

                    for(char ch: s){
                        if(ch=='A')arr.push_back(a);
                        if(ch=='B')arr.push_back(b);
                        if(ch=='C')arr.push_back(c);

                    }
                    if(arr[0]==2 || arr[n-1]==1 || count(arr.begin(), arr.end(), 1)!= n/2) continue ;
                    bool good = true;
                    int cnt2 = 0;
                    int cnt1 = 0;

                    for(int i=0;i<n;i++){
                        if(arr[i]==2)cnt2++;
                        else cnt1 ++;

                        if (cnt2>cnt1)good = false;

                    }
                    if(good){
                        cout<<"YES\n";
                        goto nxt;
                    }





                }
            }
        }   

        cout<<"NO\n";
        nxt:;







    }


    return 0;
}