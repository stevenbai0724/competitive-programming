//https://codeforces.com/problemset/problem/893/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
   
    vector<int>arr;

    for(int i=1;i<=8;i++){
        arr.push_back((pow(2,i) -1)*(pow(2,(i-1))));
    }
    
    int n; cin>>n;

    auto it = arr.end();
    it--;
    while(true){
        if(n%*it ==0){
            cout<<*it<<"\n";
            return 0; 
        }
        it--;
    }

   
    return 0;

}