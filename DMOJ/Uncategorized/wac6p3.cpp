#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
struct DSU{ 

    vector<int>parent, sz;
    int size;
    void init(int n){
        size = n;
        parent.resize(n+1);
        sz.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
            sz[i] = 1;

        }
    }
    int find(int x){
        if(parent[x] == x)return x;
        return find(parent[x]);
    }
    void Union(int x, int y){
        x = find(x);
        y = find(y);

        if(x==y)return ;
        if(sz[x]<sz[y]){
            sz[y] += sz[x];
            parent[x] = y;
        }
        else{
            sz[x] += sz[y];
            parent[y] = x;
        }
    }

};

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;
    vector<int>arr(n);
    vector<int>sorted(n);
    vector<int>ind(n); //ind[i] represents index of arr[i] in sorted[]

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sorted = arr;
    sort(sorted.begin(), sorted.end());

    if(arr == sorted){
        cout<<"0\n";
        return 0;
    }

    for(int i=0;i<n;i++){
        int idx = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin();
        ind[i] = idx;
    }



    int lo = 0;
    int hi = 1e18;
    
    while(lo+1<hi){
        int k = (lo+hi)/2;
        bool good = true;
        DSU ds;
        ds.init(n);

        for(int i=0;i<n-1;i++){
            if(sorted[i+1]-sorted[i]<=k)ds.Union(i+1, i);
        }

        for(int i=0;i<n;i++){
            good = good && ((sorted[i] == arr[i]) || (ds.find(i) == ds.find(ind[i])) ); 
        }

        if(good) hi = k;
        else lo = k;
    }
    cout<<hi<<"\n";
    return 0;
}