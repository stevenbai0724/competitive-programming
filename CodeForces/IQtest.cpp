#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int>arr(n+1);
    int o = 0, e = 0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        o+= (arr[i]&1);
        e+= (!(arr[i]&1));
    }
    if(o == 1){
        for(int i=1;i<=n;i++){
            if(arr[i]&1){
                cout<<i<<"\n";
                return 0;
            }
        }
    }
    else{
        for(int i =1;i<=n;i++){
            if(!(arr[i]&1)){
                cout<<i<<"\n";
                return 0;
            }
        }
    }
    return 0;
    

}