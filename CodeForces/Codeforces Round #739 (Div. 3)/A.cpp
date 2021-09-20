//
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>arr{0};

    for(int i=1;i<=5000;i++){
        if(i%3!=0 && i%10!=3)arr.push_back(i);
    }


    int t; cin>>t;

    while(t--){
        
        int x; cin>>x;
        cout<<arr[x]<<"\n";
        
    }


    return 0;
}