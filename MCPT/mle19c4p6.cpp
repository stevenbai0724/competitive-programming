#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define double long double

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    string s, t, a, b, c;
    cin>>s>>a>>b>>c>>t>>a>>b>>c;

    double minute1 = 0;
    double minute2 = 0;
    string temp = "";

    for(int i=0;i<s.length();i++){
        if(s[i] == ':'){
            int num = stol(temp);
            minute1 += (double)num * (double)3600;
            temp = "";
            continue;
        }
        temp += s[i];
    }

    int N = stol(temp);
    minute1 += N*(double)60;

    temp = "";

    for(int i=0;i<t.length();i++){
        if(t[i] == ':'){
            int num = stol(temp);
            minute2 += (double)num * (double)3600;
            temp = "";
            continue;
        }
        temp += t[i];
    }

    N = stol(temp);

    minute2 += N*(double)60;


    cout<<fixed<<setprecision(3)<<(minute2 - minute1)/(double)n<<"\n";



    return 0;
}