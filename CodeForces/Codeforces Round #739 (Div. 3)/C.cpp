//
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>arr{0};

    for(int i=1;i<=32000;i++){
        arr.push_back(i*i);
    }

    int t; cin>>t;

    while(t--){ 
        int x; cin>>x;
        

        auto it = lower_bound(arr.begin(), arr.end(), x);
        if(*it==x){
            cout<<it-arr.begin()<<" "<<1<<"\n";
            continue;
        }
        auto before = it; before--;

        int move = x-*before;

        pair<int, int> cur = {0, it-arr.begin() };

        while(move>0 && cur.first<it-arr.begin()){
            move--;
            cur.first++;
        }
        while(move>0 && cur.second>1){
            move--;
            cur.second--;
        }

        cout<<cur.first<<" "<<cur.second<<"\n";

        
    }


    return 0;
}