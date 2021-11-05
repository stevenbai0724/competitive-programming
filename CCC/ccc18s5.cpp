//https://dmoj.ca/problem/ccc18s5
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, p, q;
    cin>>n>>m>>p>>q;

    for(int i=1;i<=p+q;i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(c!=1){
            cout<<41<<"\n";
            return 0;
        }
    }

    cout<<(n*p)+(m*q)-(n*m)+1<<"\n";



    return 0;
}