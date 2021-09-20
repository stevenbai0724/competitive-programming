//https://codeforces.com/problemset/problem/1367/B
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        
        int n;cin>>n;
        vector<int>arr(n);
        int even = 0;
        int odd = 0;

        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%2 == 0 && i%2 !=0)even++;
            else if (arr[i]%2==1 && i%2!=1)odd++;

        }
        if(odd==0 && even==0){
            cout<<0<<"\n";
            continue;
        }
        if(odd!=even){
            cout<<-1<<"\n";
            continue;
        }
        cout<<even<<"\n";

    }

    return 0;
}