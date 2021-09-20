//
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;

        string s; cin>>s;

        int n  = s.length();
        bool blank = (n&1 && s[n/2]=='?');
        for(int i=0;i<=n/2;i++){
            char first = s[i];
            char second = s[n-1-i];

            if((first!='?' && second!='?') && first!=second){
                cout<<-1<<"\n";
                goto nxt;
            }

            if(first=='?' && second!='?')s[i] = second;

            if(first!='?' && second=='?')s[n-1-i] = first;
            
        }
        for(int i=0;i<n;i++){
            if(s[i]=='0')a--;
            if(s[i]=='1')b--;
        }
        if(a<0 || b<0 || (b&1 && a&1) || (!blank && (b&1||a&1)) ){
            cout<<-1<<"\n";
            
            goto nxt;
        }

        if(blank){
            if(a&1){
                s[n/2]='0';
                a--;
            }
            if(b&1){
                s[n/2]='1';
                b--;
            }
        }

        if(a){
            for(int i=0;i<n;i++){
                if(s[i]=='?'){
                    s[i] = '0';
                    s[n-1-i] = '0';
                    a-=2;
                    
                    if(a==0)break;
                }
            }

        }

        if(b){

            for(int i=0;i<n;i++){
                if(s[i]=='?'){
                    s[i] = '1';
                    s[n-1-i] = '1';
                    b-=2;
                    
                    if(b==0)break;
                }
            }
        }

        cout<<s<<"\n";

        nxt:;


    }
}