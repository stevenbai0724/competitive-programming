//https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    
    int n, m;
    cin>>n>>m;
    vector<int>a(n+2);
    vector<int>b(m+2);
    int ans = 0;

    for(int i =1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    int pt = 1;
    for(int i=1;i<=m;i++){
        int cur = b[i];
        int cnt1 = 1;
        int cnt2 = 1;

        while(i<m && b[i+1]==cur){
            i++;
            cnt1++;
        }
        bool found = false;
        while(pt<=n){
            if(a[pt]==cur){
                found = true;

                while(pt<n && a[pt+1]==cur){
                    pt++;
                    cnt2++;
                }
                break;
            }
            if(a[pt]>cur){
                break;
            }
            pt++;
        }
        if(!found)continue;


        ans += (cnt1 * cnt2);
    

    }
    cout<<ans<<"\n";



    return 0;
}