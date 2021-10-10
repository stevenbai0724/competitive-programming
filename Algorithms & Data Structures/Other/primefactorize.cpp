//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int mx = 0;
    int num = 0;
    for(int t=(int)(1e12-10);t<=(int)1e12;t++){
        int n = t;
        int temp = n;

        int factors = 1;
        for(int i=2;i*i<=temp;i++){
            int cnt = 0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            if(cnt!=0)factors *= (cnt+1);

        }
        if(n>1){
            factors += 1;
        }
        if(factors>mx){
            mx = factors;
            num = t;
        }
    
    }
    cout<<num<<" "<<mx<<" factors\n";


    return 0;
}