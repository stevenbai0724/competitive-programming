//https://codeforces.com/problemset/problem/80/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);


    int n, m;
    cin>>n>>m;
    int next = 0;
    vector<bool>prime(51, true);
    prime[0] = false;
    prime[1] = false;


    for(int i =2;i<=8;i++){
        if(prime[i]){
            for(int j=2;j*i<=50;j++){
                prime[i*j] = false;
            }
        }
    }
    for(int i=n+1;i<=50;i++){
        if(prime[i]){
            next = i;
            break;
        }
    }
    if(next==m)cout<<"YES";
    else cout<<"NO";


    return 0;

}