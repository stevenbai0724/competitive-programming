//https://codeforces.com/problemset/problem/146/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    string s;
    cin>>n>>s;
    int sum1 = 0;
    int sum2 = 0;
    for(int i=0;i<n/2;i++){
        if((int)s[i] -48!=4 &&(int)s[i] -48!=7){
            cout<<"NO";
            
            return 0;
        }
        sum1+=(int)s[i];
    }
    for(int i=n/2;i<n;i++){
        if((int)s[i] - 48!=4 && (int)s[i] - 48!=7){
            cout<<"NO";
            return 0;
        }
        sum2+=(int)s[i];
    }
    if(sum2==sum1)cout<<"YES";
    else cout<<"NO";


    return 0;
}