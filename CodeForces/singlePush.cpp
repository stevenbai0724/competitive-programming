//https://codeforces.com/problemset/problem/1253/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    for(t;t>0;t--){
        int n; cin>>n;
        vector<int>a(n+1);
        vector<int>b(n+1);
        vector<int>diff(n+1);
        bool neg =false;
        bool found = true;
        int l = 0; int r = 0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i = 1;i<=n;i++){
            cin>>b[i];
        }

        for(int i=1;i<=n;i++){
            diff[i] = b[i] - a[i];
            if(diff[i]<0)neg = true;
        }
        if(neg){
            cout<<"NO"<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++){
            if(diff[i]!=0){
                l = i;
                break;
            }
        }
        for(int i=n;i>=1;i--){
            if(diff[i]!=0){
                r = i;
                break;
            }
        }
        for(int i=l;i<r;i++){
            if(diff[i]!=diff[i+1]){
                found =false;
                break;
            }
        }
        if(found)cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}