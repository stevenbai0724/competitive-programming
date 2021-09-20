//https://codeforces.com/problemset/problem/1237/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;
    bool small = false;


    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(abs(x)%2==1){
            if(small){
                if(x>0){
                    cout<<x/2<<"\n";
                    small = !small;
                    continue;
                }
                else{
                    cout<<(x/2)-1<<"\n";
                    small = !small;
                    continue;
                }
            }
            else{
                if(x>0){
                    cout<<x/2+1<<"\n";
                    small = !small;
                    continue;
                }
                else{
                    cout<<x/2<<"\n";
                    small = !small;
                    continue;
                }
            }
        }
        cout<<x/2<<"\n";
    }
    return 0;
}