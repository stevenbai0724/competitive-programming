//https://codeforces.com/contest/1549/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;
        vector<bool>capture(n+1);
        string enemy, home;
        cin>>enemy>>home;

        for(int i=0;i<n;i++){
            capture[i] = (enemy[i]=='1');
        }
        int ans = 0;
        
        for(int i=0;i<n;i++){
            if(home[i]=='1'){
                if(enemy[i]=='0'){
                    ans++;
               
                    continue;
                }
                if(i>0){
                    if(capture[i-1]){
                        capture[i-1] = false;
                        ans++;
                      
                        continue;
                    }
                    
                }
                if(i<n-1){
                    if(capture[i+1]){
                        capture[i+1] = false;
                        ans++;
                      
                    }
                }
            
            }
        }
        cout<<ans<<"\n";


        

    }


    return 0;
}