//https://dmoj.ca/problem/ds1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
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
bool comp(pair<int,int> a, pair<int, int> b){
    if(a.first<b.first)return true;
    else if(a.first>b.first)return false;
    else{
        return a.second<b.second;
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;cin>>t;
    set s;
    BIT b;
    b.init(t);

    vector<pair<int, int>>edge;

    for(int i=1;i<=t;i++){
        int x; cin>>x;
        edge.push_back({x, i});
    }
    sort(edge.begin(), edge.end(), comp);

    double total = 0;
    for(auto e: edge){
        int entry = e.second;
        int place = entry+1;
        b.update(entry, 1);
        place -= (b.query(1, entry));
        total += place;
 
    }
    cout<<fixed<<setprecision(2);
    cout<<total/(double)t<<"\n";


    

    return 0;
}