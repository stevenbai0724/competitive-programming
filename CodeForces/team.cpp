#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int count = 0;
    for(int i = 0;i<n;i++){

        int s = 0;
        int c;
        cin>>c; s+=c;
        cin>>c; s+=c;
        cin>>c; s+=c;

        if(s>=2) count++;
    }
    cout<<count;

    return 0;
}