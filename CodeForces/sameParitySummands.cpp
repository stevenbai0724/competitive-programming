#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    
    for(int nigs = 0; nigs<t; nigs++){

        int x,y;
        cin>>x>>y;

        if( (x-(y-1))%2 ==1 && x-(y-1) >0 ){
            cout<<"YES"<<"\n";
            for(int i =1; i<y;i++){
                cout<<1<<" ";
            }
            cout<<x-(y-1)<<"\n";
            continue;
        }
        if( (x-((y-1)*2)) %2==0 && x-((y-1)*2)>0) {
            cout<<"YES"<<"\n";
            for(int i =1; i<y;i++){
                cout<<2<<" ";
            }
            cout<<(x-((y-1)*2))<<"\n";
            continue;
        }
        else cout<<"NO"<<"\n";
    }
    return 0;

}