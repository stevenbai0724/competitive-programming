//https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/A
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, s;
    cin>>n>>s;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    int sum = 0;
    int l = 1;
    int mx = 0;

    for(int r = 1;r<=n;r++){
        sum += arr[r];
        while(sum>s){
            sum-=arr[l];
            l++;
        }
        mx = max(mx, r-l+1);

    }
    cout<<mx<<"\n";

    return 0;
}