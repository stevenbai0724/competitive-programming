//https://dmoj.ca/problem/ccc16j4
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin>>s;

    int hr = stoi(s.substr(0,2));
    int mn = stoi(s.substr(3));

    mn += (hr*60);
    int dis = 0;

    int ans = 0;

    for(int i=mn+1;i<=mn+240;i++){
        if((420<i && i<=600) || (900<i && i<=1140)) dis ++;
        else dis += 2;

        if(dis==240){
            ans = i;
            break;
        }
        
    }   
    hr = ans/60%24;
    mn = ans%60;

    cout<<(hr<10 ? "0" + to_string(hr) : to_string(hr))<<":"<<(mn<10 ? "0"+ to_string(mn) : to_string(mn))<<"\n";





    return 0;
}