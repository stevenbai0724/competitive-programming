//https://dmoj.ca/problem/gfssoc2j2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int a = 1, b = 1;
    int n; cin>>n;
    while(n--){
        if(a%13 == 0 && a%7 == 0)cout<<"Fizz Fuzz ";
        else if (a%13 == 0)cout<<"Fuzz ";
        else if(a%7 == 0)cout<<"Fizz ";
        else cout<<a<<" ";

        if(b%13 == 0 && b%7 == 0)cout<<"Fizz Fuzz";
        else if (b%13 == 0)cout<<"Fuzz";
        else if(b%7 == 0)cout<<"Fizz";
        else cout<<b;

        a ++;
        b += 2;
        cout<<"\n";
    }
    return 0;
}