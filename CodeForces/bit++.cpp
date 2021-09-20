//https://codeforces.com/problemset/problem/282/A
#include <bits/stdc++.h>
using namespace std;
int main(){

    int n; cin>>n;
    int count = 0;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        if(s=="++X" ||s=="X++")count++;
        else count--;
    }
    cout<<count;

}
