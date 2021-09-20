//https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/B
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    
    int n, m;
    cin>>n>>m;
    vector<int>a(n+2);
    vector<int>b(m+2);

    for(int i =1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }

    int j = 0;

    for(int i=1; i<=m;i++){
        while(j<n && a[j+1]<b[i]){
            j++;
        }
        cout<<j<<" ";
    }
    cout<<"\n";


    return 0;
}