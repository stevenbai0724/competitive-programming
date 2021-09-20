//https://codeforces.com/problemset/problem/1195/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;

int check(int c){
    int movesAdd = n-c;
    return (movesAdd)*(movesAdd+1)/2 - c;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>k;

    int l = 0;
    int r = n-1;

    while(l+1<r){
        int m = (l+r)/2; //finding candies eaten
        if(check(m)==k){
            l = m;
            break;
        }
        else if(check(m)<k)r = m;
        else l = m;
    }
    cout<<l<<"\n";
   
    return 0;

}