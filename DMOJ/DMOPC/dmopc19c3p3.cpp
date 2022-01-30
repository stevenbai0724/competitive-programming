#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
struct BIT{
    vector<int>arr;
    int size;
    void init(int n){
        arr.resize(n+1);
        size = n;
    }
    void update(int x, int val){
        for(int a = x; a <= size; a+=a&-a){
            arr[a] += val;
        }
    }
    int query(int x){
        int sum = 0;
        for(int a = x; a>=1; a-=a&-a){
            sum += arr[a];
        }
        return sum;
    }
    void change(int x, int val){
        int v = query(x) - query(x-1);
        update(x, val - v);
    }
    int query(int x, int y){
        return query(y) - query(x-1);
    }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    BIT bit;
    bit.init(5e5);

    int ans = 0;
    int sum = 0;
    int mod = 2e5+1;
    bit.update(mod, 1);
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(x == 2)x = -1;
        sum += x;


        ans += bit.query(sum-1 + mod);

        bit.update(sum+mod,1);
    }

    cout<<ans<<"\n";

    return 0;
}
