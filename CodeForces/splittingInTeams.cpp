#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int count1 = 0;
    int count2 = 0;
    int ans;

    for(int i =0;i<n;i++){
        int x; cin>>x;
        if(x==1)count1++;
        else count2++;
    } 
    if(count2==0) ans = count1/3;
    else if(count1<count2) ans = count1;
    else ans = (count1-count2)/3 + count2;

    cout<<ans;

    return 0;
}