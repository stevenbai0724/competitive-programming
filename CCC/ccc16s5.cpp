//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

int getDec(int n, string s){
    int cnt = 0;
    int ans = 0;
    assert(n == s.length());
    for(int i=n-1;i>=0;i--){
        if(s[i] == '1')ans += 1<<cnt;
        cnt++;
    }
    return ans;
}
string getBinary(int n, int x){
    string s = "";

    for(int i=n-1;i>=0;i--){
        if((1<<i)<=x){
            x -= (1<<i);
            s.push_back('1');
        }
        else s.push_back('0');
    }
    return s;
}


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;
    string s; cin>>s;

    vector<int>arr(2*n+1);

    for(int i=0;i<n;i++){
        arr[i+1] = s[i] == '1';
        arr[i+1+n] = arr[i+1];
    }
    vector<bool>vis(4e4);
    vector<int>decrypt;
    vector<int>ind(4e4);

    int cycleLen = 0;
    int pfx = 0;

    while(true){
        vector<int>temp(2*n+1);
        string cur = "";
        for(int i=1;i<=n;i++){
            cur += (char)(arr[i] + 48);
        }
        int num = getDec(n, cur);

        if(!vis[num]){
            vis[num] = true;
            decrypt.push_back(num);
            ind[num] = decrypt.size()-1;
        }
        else{
            cycleLen = decrypt.size() - ind[num];
            pfx = ind[num];
            break;
        }

        for(int i=2;i<=n+1;i++){
            temp[i] = arr[i-1] ^ arr[i+1];
            if(i<=n)temp[i+n] = temp[i];
        }
        temp[1] = temp[n+1];

        arr = temp;
    }
    assert(pfx == 1);
    if(k<pfx)cout<<getBinary(n, decrypt[k])<<"\n";
    else{
        k-=pfx;
        int pos = k%cycleLen;
        cout<<getBinary(n, decrypt[pfx+pos])<<"\n";
    }




    return 0;
}