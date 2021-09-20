#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    
    int n;  cin>>n;
    int group = 0;
    int pos = 0;

    if(n ==1) cout<<"Sheldon";
    else if (n ==2) cout<<"Leonard";
    else if (n ==3) cout<<"Penny";
    else if (n ==4) cout<<"Rajesh";
    else if (n ==5) cout<<"Howard";

    else{
        while( pos <n){
            
            pos += 5* (pow(2, group));
            group++;
        }
        int start = pos - (5 *(pow(2,group-1)));
        int ans = (n-start)/pow(2, group-1);


        if(ans ==0) cout<<"Sheldon";
        else if (ans ==1) cout<<"Leonard";
        else if (ans ==2) cout<<"Penny";
        else if (ans ==3) cout<<"Rajesh";
        else if (ans ==4) cout<<"Howard";
        else cout<<"error";
    }
    


    return 0;
}