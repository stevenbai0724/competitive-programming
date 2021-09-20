//https://codeforces.com/problemset/problem/1009/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<int>games(n+1);
    vector<int>bills(m+1);
    for(int i =1;i<=n;i++){
        cin>>games[i];
    }
    for(int i=1;i<=m;i++){
        cin>>bills[i];
    }

    int j= 1;
    int i =1;
    int count = 0;

    
    for(j;j<=n;j++){

        if(games[j]<=bills[i]){
            i++;
            count++;
        }
        if(count==m)break;
    }
    cout<<count;
    
    return 0;
}