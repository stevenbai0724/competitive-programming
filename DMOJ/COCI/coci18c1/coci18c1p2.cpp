//
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool isNum(string s){
    for(char c: s){
        if(!(c>='0' && c <= '9'))return false;
    }
    return true;
}
struct DSU{
    vector<int>parent, sz, val;
    void init(int n){
        parent.resize(n+1);
        sz.resize(n+1);
        val.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x){
        if(parent[x] == x)return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    bool combine(int x, int y){
        int va1 = val[find(x)];
        int va2 = val[find(y)];

        if(va1 == 0 || va2 == 0)return true;
        if(va1 == va2)return true;
        return false;

    }
    void Union(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y)return;
        if(sz[x] < sz[y]){
            sz[y] += sz[x];
            if(val[y] == 0)val[y] = val[x];
            parent[x] = y;
        }
        else{
            sz[x] += sz[y];
            if(val[x] == 0)val[x] = val[y];
            parent[y] = x;
        }
    }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<string>arr1(n+1), arr2(n+1);
    map<string, int>mp;
    int id = 1;
    for(int i=1;i<=n;i++){
        cin>>arr1[i];
        if(!mp[arr1[i]]){
            mp[arr1[i]] = id;
            id++;
        }

    }
    for(int i=1;i<=n;i++){
        cin>>arr2[i];
        if(!mp[arr2[i]]){
            mp[arr2[i]] = id;
            id++;
        }
    }
    bool good = true;
    
    DSU ds;
    ds.init(1e5+2);

    for(int i=1;i<=n;i++){
        string a = arr1[i];
        string b = arr2[i];
        if(a == b)continue; //same
        if(isNum(a) && isNum(b)){ //both nums
            cout<<"NE\n";
            return 0;
        }
        else if(isNum(a) || isNum(b)){ // 1 num
            if(isNum(b))swap(a, b);
            //a is now the number
            int v = stol(a);

            int p = ds.find(mp[b]);
            if(ds.val[p] == 0)ds.val[p] = v;
            else if(ds.val[p] != v){
                cout<<"NE\n";
                return 0;
            }
        }
        else{
            int x = mp[a];
            int y = mp[b];

            if(ds.combine(x, y)){
                ds.Union(x, y);
            }
            else {
                cout<<"NE\n";
                return 0;
            }


        }

    }

    cout<<"DA\n";




    return 0;
}