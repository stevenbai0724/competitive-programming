#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        bool good = true;
        for(int i=0;i<n;i++){
            int j = i;
            int B = 0;
            int R = 0;
            if(s[i] == 'W') continue;
            else if(s[i] == 'R') R++;
            else B++;

            while(j < n-1 && s[j+1] != 'W'){
                j++;
                if(s[j] == 'B') B++;
                else R++;
            }
            if(B == 0 || R == 0)good = false;
            i = j;

        }

        cout << (good ? "YES\n" : "NO\n");

    }

    return 0;
}