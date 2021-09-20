//https://codeforces.com/problemset/problem/279/B
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;

    vector<int>arr(n+2);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int mx = 0;
    int sum = arr[1];
    int j = 1;
    for(int i=1;i<=n;i++){
        sum-=arr[i-1];
      

        if(sum>k)continue;

        while(sum+arr[j+1]<=k && j<n){
            j++;
            sum+=arr[j];
        }
        mx = max(mx, j-i+1);

        
    }
    cout<<mx<<"\n";


    return 0;
}