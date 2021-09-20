//https://dmoj.ca/problem/cco06p1
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int cnt = 0;
vector<int>arr;
vector<bool>vis(36000);

bool good(int m){

    for(int i=0;i<cnt;i++){
        int cur = arr[i];
        int checker = 0;
        for(int j=0;j<=m;j++){
            int nxt = (cur+j)%36000;
            if(vis[nxt])checker++;
        }
        if(checker==cnt)return true;
    }
    return false;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n;

    for(int i=0;i<n;i++){
        string s; cin>>s;
        double x; cin>>x;
        x*=100;

        if(!vis[(int)x]){
            cnt++;
            arr.push_back((int)x);
        
        }
        
        vis[(int)x] = true;
    }
    if(cnt==1){
        cout<<0<<"\n";
        return 0;
    }
    sort(arr.begin(), arr.end());

    int l = 0;
    int r = 35999;
    while(l+1<r){
        int m = (l+r)/2;
        if(good(m))r = m;
        else l = m;
    }
    
    cout<<ceil((r/100.0)*12)<<"\n";




}