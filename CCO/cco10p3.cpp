//https://dmoj.ca/problem/cco10p3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

struct BIT{
    vector<int>arr;
    int size;
    void init(int n){
        size = n;
        arr.resize(n+5);
    }
    void update(int x, int val){ //add
        for(int a = x; a<=size; a+=a&-a){
            arr[a]+=val;
        }
    }
    int query(int x){
        int sum = 0;
        for(int a = x; a>0; a-=a&-a){
            sum+=arr[a];
        }
        return sum;
    }
    void change(int x, int val){ //change
        int v = query(x)-query(x-1);
        update(x,val-v);
    }
    int query(int x, int y){//inclusive
        return query(y)-query(x-1);
    }
};
struct edge{
    char c;
    int x, y;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<edge>queries;
    vector<int>ratings{(int)-1e18};
   
    unordered_map<int, int>player, cur;

    for(int i=1;i<=n;i++){
        char c; cin>>c;
        int x; cin>>x;
        if(c!='Q'){
            int y; cin>>y;
            queries.push_back({c,x,y});
            ratings.push_back(y);
        }
        else{
            queries.push_back({c,x,0});
        }

    }
    sort(ratings.begin(), ratings.end());
    int sz = ratings.size()-1;

    BIT bit;
    bit.init(sz);
    int total = 0;
    for(auto e: queries){
        int ind = lower_bound(ratings.begin(), ratings.end(), e.y) - ratings.begin();
        if(e.c == 'N'){

            bit.update(ind, 1);
            cur[e.x] = ind;
            player[ind] = e.x;
            total ++;
        }
        if(e.c == 'M'){
            bit.update(cur[e.x], -1);
            bit.update(ind, 1);
            player[ind] = e.x;
            cur[e.x] = ind;
        }
        if(e.c == 'Q'){
            int target = total - e.x + 1;

            int L = 0;
            int R = sz;
            while(L+1<R){
                int m = (L+R)/2;
                if(bit.query(1,m) >= target) R = m;
                else L = m;
            }
            cout<<player[R]<<"\n";
        }
    }


    

    return 0;
}