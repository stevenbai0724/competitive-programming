#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int sum = 0;

    vector<int>arr(n+1);
    vector<int>psa(n+1);
    psa[0] = 0;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i];
        psa[i] = sum;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=n-i;j++){
            int start = j;
            int end = j+i;
            int len = i+1;

            int ones = psa[end]-psa[start-1];
            int zeros = len-ones;
            
            ans = max(ans, sum-ones+zeros);

        }       
    }
    cout<<ans<<"\n";



    return 0;
}