//
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);


    vector<int>arr{1};
    int p = 1;
    for(int i=1;i<=60;i++){
        p*=2;
        arr.push_back(p);
     
    }

  

    int t; cin>>t;

    while(t--){

        int x; cin>>x;
        string s = to_string(x);
        int ans = 1e9;

        if(*lower_bound(arr.begin(), arr.end(), x) == x){
            cout<<0<<"\n";
            continue;
        }

        for(int i=0;i<=60;i++){
            string require = to_string(arr[i]);
            int n = require.length();
            int cur = 0;
            int tempAns = 0;

            string temp = s;
            int m = temp.length();
            string subset = "";

            for(int j=0;j<m;j++){
                if(temp[j]==require[cur]){
                    subset+= temp[j];
                    cur++;

                }
                if(cur>=n)break;
            }

            tempAns += m - subset.length();

            tempAns += n - subset.length();

            ans = min(ans, tempAns);

        }
        cout<<ans<<"\n";



        
    }


    return 0;
}