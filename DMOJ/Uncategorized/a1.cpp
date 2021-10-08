//https://dmoj.ca/problem/a1
    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    using namespace std;
    using namespace __gnu_pbds;
    #define int long long
    #define string std::string


    signed main(){
        cin.tie(nullptr)->sync_with_stdio(false);
        int cnt = 0;
        int t; cin>>t;
        string nothing; getline(cin, nothing);
        while(t--){

            string s; getline(cin, s);
            string temp = s.substr(0,1);
            int j = 0;
            while(s[j+1]>=48 && s[j+1]<=57 && j+1<s.length()){
                j++;
                temp += s[j];
            }
            int ind = stoi(temp);

            string ans = "";

            string str = s.substr(j+2);

            for(int i=0;i<str.length();i++){
                if(i+1 == ind)continue;
                ans += str[i];
            }
            cout<<++cnt<<" "<<ans<<"\n";
        }



        return 0;
    }