//https://codeforces.com/problemset/problem/177/A1
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<vector<int>>arr(n+1, vector<int>(n+1));
    int sum = 0;
    int mid = n/2 + 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x; cin>>x;
            if(i==j) sum+=x;
            else if(i==(j- 2*(j-mid))) sum+=x;
            else if(i==mid ||j==mid) sum+=x;

        }
    }
    cout<<sum;
    

    return 0;
}