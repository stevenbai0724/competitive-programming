#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n;
    vector<int>A(n+1);

    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    cin>>m;
    vector<int>B(m+1);
    for(int i=1;i<=m;i++){
        cin>>B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    cout<<A[n]<<" "<<B[m];

    return 0;
}