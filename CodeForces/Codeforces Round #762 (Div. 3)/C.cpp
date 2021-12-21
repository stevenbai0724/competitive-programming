//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//order_of_key
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int t; cin>>t;
    while(t--){
        string a, s;
        cin>>a>>s;
        string b = "";
        string temp1 = "";
        string temp2 = a;
        if(s.length() < a.length()){
            cout<<-1<<"\n";
            continue;
        }
        for(int i=1; i<= (s.length() - a.length()); i++){
            temp1 += '0';
        }
        a = temp1 + temp2;

        int R1 = a.length() - 1;
        int R2 = s.length() - 1;
        string cur = "";
        bool bad = false;
        while(R1 >= 0 && R2 >= 0){
            int top = a[R1] - '0';
            int cur = s[R2] - '0';

            if(cur - top >= 0){
                b += (cur - top) + '0';
                R1--;
                R2--;
            }
            else{
                cur += 10;
                b += (cur - top) + '0';
                R1--;
                R2-=2;
            }

        }
        if(bad)continue;
        int diff = a.length() - b.length();
        temp1 = "";
        temp2 = a;
        
        if(diff < 0){
            for(int i=1;i<=diff;i++) temp1 += '0';
        }
        if(diff > 0){
            for(int i=1;i<=diff;i++) b += '0';
        }
        a = temp1 + temp2;

        reverse(b.begin(), b.end());


        vector<string>check;
        for(int i=a.length()-1;i>=0;i--){
            int x = a[i] - '0';
            int y = b[i] - '0';
            check.push_back(to_string(x+y));
        }
        reverse(check.begin(), check.end());
        string chk = "";
        for(auto nxt: check){
            chk += nxt;
        }
        if(chk == "" || b == ""){
            cout<<-1<<"\n";
            continue;
        }
        chk.erase(0, chk.find_first_not_of('0'));
        b.erase(0, b.find_first_not_of('0'));

    
        if(chk == s)cout<<b<<"\n";
        else cout<<-1<<"\n";
        

    }

    return 0;
}