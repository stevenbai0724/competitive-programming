//https://dmoj.ca/problem/ccc07j2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    map<string, string>mp;

    mp["CU"] = "see you\n";
    mp[":-)"] = "I'm happy\n";
    mp[":-("] = "I'm unhappy\n";
    mp[";-)"] = "wink\n";
    mp["(~.~)"] = "sleepy\n";
    mp["TA"] = "totally awesome\n";
    mp["CCC"] = "Canadian Computing Competition\n";
    mp["CUZ"] = "because\n";
    mp["TY"] = "thank-you\n";
    mp["YW"] = "you're welcome\n";
    mp["TTYL"] = "talk to you later\n";

    while(true){
        string s; cin>>s;
        if(mp[s]==""){
            cout<<s<<"\n";
        }
        else cout<<mp[s];

        if(s=="TTYL")break;
    }

    return 0;
}