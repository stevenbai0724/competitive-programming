#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    for(int i =0;i<n;i++){

        string s; cin>>s;
        int btw = 0;
        if(s.length() <=10){
            cout<<s<<"\n";
        }
        else{
            btw = s.length()-2;
            cout<<s[0]<<btw<<s[s.length()-1]<<"\n";
        }

    }


    return 0;
}