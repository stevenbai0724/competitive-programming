//https://codeforces.com/contest/1471/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
int x;

int div(int n){
    int count = 0;
    while(n%x==0){
        count++;
        n/=x;
    }
    return count;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n;
        cin>>n>>x;
        vector<int>arr(n+1);
        vector<int>num(n+1);
        int sum = 0;
        bool found = true;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            sum+=arr[i];
            num[i] = div(arr[i]);
        }
        while(found){
            for(int i=1;i<=n;i++){
                if(num[i]==0){
                    found = false;
                    break;
                }
                sum+=arr[i];
                num[i]--;
            }
        }
        cout<<sum<<"\n";
        
        
    }

    return 0;
}