//https://codeforces.com/problemset/problem/1520/E
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    
    while(t--){
        int n; cin>>n;

        string s; cin>>s;

        int cnt = 0;
        vector<int>ind{0};
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                cnt++;
                ind.push_back(i);
            }
        }
        if(cnt<=1){
            cout<<"0\n";
            continue;
        }
        int m = ind.size()-1;
        int cur = 1;    
        int ans = 0;
        int L = m/2;
        int R = m/2;
        if(cnt%2==0)L--;
        for(int i= (ind[(m+1)/2]) - L; i<= (ind[(m+1)/2]) + R; i++){
            ans += abs(ind[cur]-i);
            cur++;
        }
        cout<<ans<<"\n";




    }


    return 0;
}