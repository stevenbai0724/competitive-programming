//https://codeforces.com/problemset/problem/1291/B
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    
    while(t--){
        int n; cin>>n;

        vector<int>arr(n+1);

        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

        vector<int>case1(n+1), case2(n+1), LG(n+1), RG(n+1);
        case1[0] = -1;

        for(int i=1;i<=n;i++){
            case1[i] = case1[i-1];
            case1[i]++;
        }
        case2[1] = n-1;
        for(int i=2;i<=n;i++){
            case2[i] = case2[i-1]-1;
        }

        for(int i=1;i<=n;i++){
            if(arr[i]>=case1[i])LG[i] = 1;
            else break;
        }
        for(int i=n;i>=1;i--){
            if(arr[i]>=case2[i])RG[i] = 1;
            else break;
        }

        bool ans = false;
        for(int i=1;i<=n;i++){
            ans |= (LG[i]==1 && RG[i]==1);
        }
        if(ans)cout<<"Yes\n";
        else cout<<"No\n";
        
    
        
    }


    return 0;
}