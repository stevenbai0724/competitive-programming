//https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/A
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    
    int n, m;
    cin>>n>>m;
    vector<int>a(n+2);
    vector<int>b(m+2);

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    a[n+1] = 1e18;
    b[m+1] = 1e18;

    vector<int>ans;

    int pt1 = 1;
    int pt2 = 1;

    int cnt = 0;
    while(cnt!=(n+m)){
        
        if(a[pt1]<b[pt2]){
            ans.push_back(a[pt1]);
            pt1++;
        }
        else{
            ans.push_back(b[pt2]);
            pt2++;
        }
        cnt++;
    }
    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<"\n";



    return 0;
}