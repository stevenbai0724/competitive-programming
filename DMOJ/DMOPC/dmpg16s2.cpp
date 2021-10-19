//https://dmoj.ca/problem/dmpg16s2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k, d;
    cin>>n>>k>>d;

    d = min(d, (int)(log(n)/log(k)));

    if(n==0){
        cout<<0<<"\n";
        return 0;
    }
    if(d==0){
        cout<<n<<"\n";
        return 0;
    }

    deque<int>q;
    q.push_back(1);

    for(int i=1;i<=d;i++){
        q.push_back(q.back() * k);
    }

    int sum = n;
    int cnt = 0;
    while(!q.empty()){
        int cur = q.back();

        q.pop_back();
        if(cur>sum)continue;
        cnt += sum/cur;
        sum %= cur;
        if(sum==0)break;
    }
    cout<<cnt<<"\n";




    return 0;
}